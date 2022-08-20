const char webpage[] = R"=====(
<!DOCTYPE html>
<html>
<style type="text/css">
</style>
<body style="background-color: #f9e79f ">
<center>
<div>
<h1>AJAX BASED ESP8266 WEBSERVER</h1>
</div>
 <br>
<div><h2>
  Dist(cm): <span id="adc_val">0</span><br><br>
</h2>
</div>
<script>

setInterval(function() 
{
  getData();
}, 2000); 
function getData() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("adc_val").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "adcread", true);
  xhttp.send();
}
</script>
</center>
</body>
</html>
)=====";
