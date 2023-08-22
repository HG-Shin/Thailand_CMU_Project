#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <WiFi.h>
#include <Firebase.h>
#include <time.h>

#define DHTPIN 16 
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

#define WiFi_SSID       ""
#define WiFi_PASSWORD   ""
#define DB_URL          ""
#define DB_PASSWORD     ""

FirebaseData fbdo;  // Firebase 데이터 객체
FirebaseJson json;
String roomName = "/N4-601"; //아누이노 설치하는 강의실 이름 '/'포함 해야함

const char* ntpServer = "pool.ntp.org";
char* curTime;
uint8_t timeZone = 9;
uint8_t summerTime = 0; // 3600

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
  /*WiFi connection*/
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
  float temperature = dht.readTemperature();  
  if (isnan(temperature)) {
    Serial.println("Temperature sensor error");
  }
  else {
    Serial.print("Temperature: ");
    Serial.println(temperature); //소수점 1자리까지 출력
    
    json.add("temperature", temperature); //PUSH
  }

  /*Humidity Sensor*/
  float humidity = dht.readHumidity();
  if (isnan(humidity)) {
    Serial.println("Humidity sensor error");
  }
  else {
    Serial.print("Humidity: ");
    Serial.println(humidity);

    json.add("humidity", humidity);
  }

  /*Light Sensor*/
  float lux = analogRead(34);

  Serial.print("Lux: ");
  Serial.println(lux);

  json.add("lux", lux);

  /*Sensor measurement time*/ 
  time_t now = time(nullptr);
  curTime = ctime(&now);
  
  Serial.println(ctime(&now));
  Serial.println("");
  
  json.add("time", curTime);
  Firebase.pushJSON(fbdo, "/DB_Storage" + roomName, json);
  
  json.set("/temperature", temperature); //set (real time)
  Firebase.updateNode(fbdo,"/Realtime" + roomName, json);

  json.set("/humidity", humidity);
  Firebase.updateNode(fbdo,"/Realtime" + roomName, json);

  json.set("/lux", lux);
  Firebase.updateNode(fbdo,"/Realtime" + roomName, json);
  
  delay(600000);  //60sec
}
