"use strict";(self["webpackChunkcapstone_project"]=self["webpackChunkcapstone_project"]||[]).push([[624],{2624:function(e,t,r){r.r(t),r.d(t,{default:function(){return w}});var n=r(3396);const a={class:"temperature"};function o(e,t,r,o,s,l){const u=(0,n.up)("TemparetureChart");return(0,n.wg)(),(0,n.iD)("div",a,[(0,n.Wm)(u)])}const s=(0,n._)("h1",null,"Tempareture Chart",-1),l={style:{width:"1200px"}},u={id:"graphCanvas",ref:"domRef"};function i(e,t,r,a,o,i){return(0,n.wg)(),(0,n.iD)(n.HY,null,[s,(0,n._)("div",l,[(0,n._)("canvas",u,null,512)])],64)}r(7658);var c=r(3146),p=(r(586),r(1178)),m=r(1458);const h=(0,p.iH)(m.Z);var d={name:"TemparetureChart",mounted(){var e,t=[],r=[],n=new Promise((function(n){(0,p.U2)((0,p.iU)(h,"/DB_Storage/TestRoom")).then((a=>{if(a.exists()){for(var o in e=a.val(),e){var s=e[o];for(var l in s)"temperature"===l&&t.push(s[l]),"time"===l&&r.push(s[l])}var u=!0;while(u)t.length>36?(t.shift(),r.shift()):u=!1;console.log(t),console.log(r),n({temperature:t,time:r})}}))}));n.then((e=>{console.log("eiei");const t={type:"line",data:{labels:e.time,datasets:[{label:"Temperature in test room",data:e.temperature,backgroundColor:"rgba(71, 183,132,.5)",borderColor:"#47b784",borderWidth:3}]}};console.log(e),console.log(t);const r=document.getElementById("graphCanvas");new c.kL(r,t)}))}},v=r(89);const f=(0,v.Z)(d,[["render",i]]);var g=f,C={name:"TemparetureChartView",components:{TemparetureChart:g}};const b=(0,v.Z)(C,[["render",o]]);var w=b}}]);
//# sourceMappingURL=624.d376d237.js.map