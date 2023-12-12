import { ref, child, get } from "firebase/database";
import firebaseApp from "./firebaseApp";

const dbRef = ref(firebaseApp);

export default {
  getChartData() {
    var valueArray;
    var humidity = [];
    var time = [];

    var myPromise = new Promise(function (resolve) {
      get(child(dbRef, `/DB_Storage/TestRoom`)).then((snapshot) => {
        if (snapshot.exists()) {
          //    console.log(snapshot.val());
          valueArray = snapshot.val();
          //   console.log(valueArray);

          for (var key in valueArray) {
            var obj = valueArray[key];
            for (var prop in obj) {
              if (prop === "humidity") {
                humidity.push(obj[prop]);
              }
              if (prop === "time") {
                time.push(obj[prop]);
              }
            }
          }
          console.log(humidity);
          resolve({ humidity: humidity, time: time });
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
              label: "Planetary Mass (relative to the Sun x 10^-6)",
              data: value.humidity,
              backgroundColor: "rgba(71, 183,132,.5)",
              borderColor: "#47b784",
              borderWidth: 3,
            },
          ],
        },
      };
      console.log(value);
      console.log(tempChartData);
      return tempChartData;
    });
  },
};
