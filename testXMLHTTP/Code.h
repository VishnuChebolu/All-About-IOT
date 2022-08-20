const char Code[] = 
R"=====(
<button onclick="buttonClick('1')">led1</button> 
<button onclick="buttonClick('2')">led2</button> 
<button onclick="buttonClick('3')">led3</button> 
<script>
var statusOfPins = [0,0,0]
function buttonClick(parm)
    {
      statusOfPins[parseInt(parm)-1] = statusOfPins[parseInt(parm)-1]==0?1:0;
      var xhttp = new XMLHttpRequest();
      xhttp.open("GET", "led_set?field1="+statusOfPins[0]+"&field2="+statusOfPins[1]+"&field3="+statusOfPins[2], true);
      xhttp.send();
  }
</script>
)=====";
