<template>
  <div class="humidity">
    <HumidityChart></HumidityChart>
  </div>
</template>
<script>
import HumidityChart from "@/components/HumidityChart.vue";

export default {
  name: "HumidityChartView",
  components: {
    HumidityChart,
  },
};
</script>

<style></style>
