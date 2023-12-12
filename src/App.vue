<template>
  <h1><router-link class="header" to="/">SMART GREEN CAMPUS</router-link></h1>
  <nav>
    <router-link to="/temperature">Temperature</router-link> |
    <router-link to="/humidity">Humidity</router-link> |
    <router-link to="/lux">Lux</router-link>
  </nav>
  <router-view />
</template>

<style>
h1 {
  padding-top: 30px;
}
#app {
  font-family: Avenir, Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
}

.header {
  color: #42b983;
  text-decoration: none;
  font-weight: 600;
}

.header:hover {
  color: #78dcaf;
}

nav {
  padding: 30px;
}

nav a {
  font-weight: bold;
  color: #2c3e50;
}

nav a.router-link-exact-active {
  color: #42b983;
}

#graphCanvas {
  padding-left: 190px;
  padding-bottom: 100px;
}

#graphCanvas2 {
  padding-left: 190px;
}

#text {
  text-align: center;
}

h2 {
  padding-left: 245px;
  padding-bottom: 20px;
}
</style>
