#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <WiFi.h>
#include <Firebase.h>
#include <time.h>

#define DHTPIN 16 
#define DHTTYPE DHT22
DHT_Unified dht(DHTPIN, DHTTYPE);

#define WiFi_SSID       ""
#define WiFi_PASSWORD   ""
#define DB_URL          ""
#define DB_PASSWORD     ""

FirebaseData fbdo;  // Firebase 데이터 객체
FirebaseJson json;

const char* ntpServer = "pool.ntp.org";
uint8_t timeZone = 9;
uint8_t summerTime = 0; // 3600
uint8_t n = 0;

void printLocalTime() {
  struct tm timeinfo;
  
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    return;
  }
  Serial.print("Time: ");
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
}

void setup() {
  Serial.begin(115200);
  dht.begin();

  WiFi.mode(WIFI_STA);
  WiFi.begin(WiFi_SSID, WiFi_PASSWORD);
  Serial.print("Connecting to WiFi");
  while(WiFi.status() != WL_CONNECTED) {
    delay(300);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());


  Firebase.begin(DB_URL, DB_PASSWORD);       // 인증과 설정을 적용하여 Firebase 시작
  Firebase.reconnectWiFi(true);              // Firebase 재접속 허용
  Firebase.setReadTimeout(fbdo, 1000 * 60);  // set DB read timeout to 1 minute (max 15 min)
  Firebase.setwriteSizeLimit(fbdo, "tiny");  // Size and its write timeout e.g. tiny(1s), small(10s), medium(30s), large(60s), and unlimited

  configTime(3600 * timeZone, 3600 * summerTime, ntpServer); //init and get the time
}

void loop() {
  sensors_event_t event;
  n++;
  
  if(WiFi.status() != WL_CONNECTED) {
    WiFi.begin(WiFi_SSID, WiFi_PASSWORD);
    Serial.print("Reconnecting WiFi");
    while(WiFi.status() != WL_CONNECTED) {
      delay(300);
      Serial.print(".");
    }
    Serial.println("\nWiFi Reconnected\n");
  }

  /*Temperature Sensor*/
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    Serial.println("Temperature sensor error");
  }
  else {
    Serial.print("Temperature: ");
    Serial.println(event.temperature, 1); //소수점 아래 1자리까지 출력
    
    json.set("/Data" + String(n) + "/temperature", event.temperature);
    Firebase.updateNode(fbdo,"/TestRoom", json);
  }

  /*Humidity Sensor*/
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    Serial.println("Humidity sensor error");
  }
  else {
    Serial.print("Humidity: ");
    Serial.println(event.relative_humidity, 1);

    json.set("/Data" + String(n) + "/humidity", event.relative_humidity);
    Firebase.updateNode(fbdo,"/TestRoom", json);
  }

  /*Light Sensor*/
  float lux = analogRead(34);

  Serial.print("Lux: ");
  Serial.println(lux, 1);
  json.set("/Data" + String(n) + "/Lux", lux);
  Firebase.updateNode(fbdo,"/TestRoom", json);

  /*Sensor measurement time*/ 
  printLocalTime();  
  Serial.println("");
  
  delay(10000);  //10sec  
}
