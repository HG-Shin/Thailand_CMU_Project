// Import the functions you need from the SDKs you need
import { initializeApp } from "firebase/app";
import { getDatabase } from "firebase/database";

// TODO: Add SDKs for Firebase products that you want to use
// https://firebase.google.com/docs/web/setup#available-libraries

// Your web app's Firebase configuration
// For Firebase JS SDK v7.20.0 and later, measurementId is optional
const firebaseConfig = {
  apiKey: "AIzaSyCCs1AD8sx81sHi6AoW6VJzVV4oIS_odVo",
  authDomain: "cmu-hbnu-sensor-monitoring.firebaseapp.com",
  databaseURL: "https://cmu-hbnu-sensor-monitoring-default-rtdb.firebaseio.com",
  projectId: "cmu-hbnu-sensor-monitoring",
  storageBucket: "cmu-hbnu-sensor-monitoring.appspot.com",
  messagingSenderId: "950609492098",
  appId: "1:950609492098:web:3c9ab7f5cf97071b3a9c9b",
  measurementId: "G-E2VPW3QSS9",
};

// Initialize Firebase
const app = initializeApp(firebaseConfig);

// Initialize Realtime Database and get a reference to the service
const database = getDatabase(app);

export default database;
