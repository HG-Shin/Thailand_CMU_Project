<template>
  <div class="temperature">
    <TemparetureChart></TemparetureChart>
  </div>
</template>

<script>
import TemparetureChart from "@/components/TemparetureChart.vue";

export default {
  name: "TemparetureChartView",
  components: {
    TemparetureChart,
  },
};
</script>

<style></style>
