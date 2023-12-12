<template>
  <div style="width: 1200px">
    <h2>N4-601</h2>
    <canvas id="graphCanvas2" ref="domRef"></canvas>
    <h2>Outdoor</h2>
    <canvas id="graphCanvas1" ref="domRef"></canvas>
  </div>
</template>

<script></script>

<script>
import { Chart } from "chart.js/auto";
import tempChartService from "@/tempChartService.js";
//console.log(tempChartService.getChartData());
import { ref, child, get } from "firebase/database";
import firebaseApp from "@/firebaseApp";

const dbRef = ref(firebaseApp);

export default {
  name: "MainChart",
  mounted() {
    var valueArray;
    var temperature = [];
    var time = [];
    var humidity = [];
    var lux = [];

    var myPromise = new Promise(function (resolve) {
      get(child(dbRef, `/DB_Storage/Outdoor`)).then((snapshot) => {
        if (snapshot.exists()) {
          //    console.log(snapshot.val());
          valueArray = snapshot.val();
          //   console.log(valueArray);

          for (var key in valueArray) {
            var obj = valueArray[key];
            for (var prop in obj) {
              if (prop === "temperature") {
                temperature.push(obj[prop]);
              }
              if (prop === "time") {
                time.push(obj[prop]);
              }
              if (prop === "humidity") {
                humidity.push(obj[prop]);
              }
              if (prop === "lux") {
                lux.push(obj[prop]);
              }
            }
          }
          var flag = true;
          while (flag) {
            if (temperature.length > 36) {
              temperature.shift();
              time.shift();
              humidity.shift();
              lux.shift();
            } else {
              flag = false;
            }
          }
          console.log(temperature);
          console.log(time);
          resolve({
            temperature: temperature,
            time: time,
            lux: lux,
            humidity: humidity,
          });
        }
      });
    });

    myPromise.then((value) => {
      console.log("eiei");
      const tempChartData = {
        type: "line",
        data: {
          labels: value.time,
          datasets: [
            {
              label: "Temperature",
              data: value.temperature,
              backgroundColor: "rgba(71, 183,132,.5)",
              borderColor: "#47b784",
              borderWidth: 3,
            },
            {
              label: "Humidity",
              data: value.humidity,
              backgroundColor: "#d48f70",
              borderColor: "#b76a47",
              borderWidth: 3,
            },
            {
              label: "Lux",
              data: value.lux,
              backgroundColor: "#bb85d4",
              borderColor: "#9447b7",
              borderWidth: 3,
            },
          ],
        },
      };
      console.log(value);
      console.log(tempChartData);
      const ctx = document.getElementById("graphCanvas");
      new Chart(ctx, tempChartData);
    });

    //------------------

    var valueArray2;
    var temperature2 = [];
    var time2 = [];
    var humidity2 = [];
    var lux2 = [];

    var myPromise2 = new Promise(function (resolve) {
      get(child(dbRef, `/DB_Storage/N4-601`)).then((snapshot) => {
        if (snapshot.exists()) {
          //    console.log(snapshot.val());
          valueArray2 = snapshot.val();
          //   console.log(valueArray);

          for (var key in valueArray2) {
            var obj = valueArray2[key];
            for (var prop in obj) {
              if (prop === "temperature") {
                temperature2.push(obj[prop]);
              }
              if (prop === "time") {
                time2.push(obj[prop]);
              }
              if (prop === "humidity") {
                humidity2.push(obj[prop]);
              }
              if (prop === "lux") {
                lux2.push(obj[prop]);
              }
            }
          }
          var flag = true;
          while (flag) {
            if (temperature2.length > 36) {
              temperature2.shift();
              time2.shift();
              humidity2.shift();
              lux2.shift();
            } else {
              flag = false;
            }
          }
          console.log(temperature);
          console.log(time);
          resolve({
            temperature2: temperature2,
            time2: time2,
            lux2: lux2,
            humidity2: humidity2,
          });
        }
      });
    });

    myPromise2.then((value) => {
      console.log("eiei");
      const tempChartData2 = {
        type: "line",
        data: {
          labels: value.time2,
          datasets: [
            {
              label: "Temperature",
              data: value.temperature2,
              backgroundColor: "rgba(71, 183,132,.5)",
              borderColor: "#47b784",
              borderWidth: 3,
            },
            {
              label: "Humidity",
              data: value.humidity2,
              backgroundColor: "#d48f70",
              borderColor: "#b76a47",
              borderWidth: 3,
            },
            {
              label: "Lux",
              data: value.lux2,
              backgroundColor: "#bb85d4",
              borderColor: "#9447b7",
              borderWidth: 3,
            },
          ],
        },
      };
      console.log(value);
      console.log(tempChartData2);
      const ctx = document.getElementById("graphCanvas2");
      new Chart(ctx, tempChartData2);
    });
  },
};
</script>

<style></style>
