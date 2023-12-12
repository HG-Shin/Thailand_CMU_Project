<template>
  <div style="width: 1200px">
    <h2>Outdoor</h2>
    <canvas id="graphCanvas" ref="domRef"></canvas>
    <h2>N4-601</h2>
    <canvas id="graphCanvas2" ref="domRef"></canvas>
  </div>
</template>

<script></script>

<script>
import { Chart } from "chart.js/auto";
//console.log(tempChartService.getChartData());
import { ref, child, get } from "firebase/database";
import firebaseApp from "@/firebaseApp";

const dbRef = ref(firebaseApp);

export default {
  name: "LuxChart",
  mounted() {
    var valueArray;
    var lux = [];
    var time = [];

    var myPromise = new Promise(function (resolve) {
      get(child(dbRef, `/DB_Storage/Outdoor`)).then((snapshot) => {
        if (snapshot.exists()) {
          //    console.log(snapshot.val());
          valueArray = snapshot.val();
          //   console.log(valueArray);

          for (var key in valueArray) {
            var obj = valueArray[key];
            for (var prop in obj) {
              if (prop === "lux") {
                lux.push(obj[prop]);
              }
              if (prop === "time") {
                time.push(obj[prop]);
              }
            }
          }
          var flag = true;
          while (flag) {
            if (lux.length > 36) {
              lux.shift();
              time.shift();
            } else {
              flag = false;
            }
          }
          console.log(lux);
          console.log(time);
          resolve({ lux: lux, time: time });
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

    //---------------------- graph 2

    var valueArray2;
    var lux2 = [];
    var time2 = [];

    var myPromise2 = new Promise(function (resolve) {
      get(child(dbRef, `/DB_Storage/N4-601`)).then((snapshot) => {
        if (snapshot.exists()) {
          //    console.log(snapshot.val());
          valueArray2 = snapshot.val();
          //   console.log(valueArray);

          for (var key in valueArray2) {
            var obj = valueArray2[key];
            for (var prop in obj) {
              if (prop === "lux") {
                lux2.push(obj[prop]);
              }
              if (prop === "time") {
                time2.push(obj[prop]);
              }
            }
          }
          var flag = true;
          while (flag) {
            if (lux2.length > 36) {
              lux2.shift();
              time2.shift();
            } else {
              flag = false;
            }
          }
          console.log(lux2);
          console.log(time2);
          resolve({
            lux2: lux2,
            time2: time2,
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
