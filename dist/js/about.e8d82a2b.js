"use strict";(self["webpackChunkcapstone_project"]=self["webpackChunkcapstone_project"]||[]).push([[443],{4005:function(t,e,n){n.r(e),n.d(e,{default:function(){return b}});var o=n(3396);const i={class:"humidity"};function r(t,e,n,r,a,s){const l=(0,o.up)("HumidityChart");return(0,o.wg)(),(0,o.iD)("div",i,[(0,o.Wm)(l)])}const a=(0,o._)("h1",null,"Humidity Chart",-1),s={style:{width:"1200px"}},l={id:"graphCanvas",ref:"domRef"};function u(t,e,n,i,r,u){return(0,o.wg)(),(0,o.iD)(o.HY,null,[a,(0,o._)("div",s,[(0,o._)("canvas",l,null,512)])],64)}n(7658);var c=n(3146),d=n(1178),h=n(1458);const m=(0,d.iH)(h.Z);var v={name:"HumidityChart",mounted(){var t,e=[],n=[],o=new Promise((function(o){(0,d.U2)((0,d.iU)(m,"/DB_Storage/TestRoom")).then((i=>{if(i.exists()){for(var r in t=i.val(),t){var a=t[r];for(var s in a)"humidity"===s&&e.push(a[s]),"time"===s&&n.push(a[s])}var l=!0;while(l)e.length>36?(e.shift(),n.shift()):l=!1;console.log(e),console.log(n),o({humidity:e,time:n})}}))}));o.then((t=>{console.log("eiei");const e={type:"line",data:{labels:t.time,datasets:[{label:"humidity in test room",data:t.humidity,backgroundColor:"rgba(71, 183,132,.5)",borderColor:"#47b784",borderWidth:3}]}};console.log(t),console.log(e);const n=document.getElementById("graphCanvas");new c.kL(n,e)}))}},f=n(89);const p=(0,f.Z)(v,[["render",u]]);var g=p,y={name:"HumidityChartView",components:{HumidityChart:g}};const C=(0,f.Z)(y,[["render",r]]);var b=C}}]);
//# sourceMappingURL=about.e8d82a2b.js.map