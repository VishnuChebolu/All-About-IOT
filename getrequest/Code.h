const char Code[] = 
R"=====(
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>

<body>
    <h1 id="value">Hehe</h1>
</body>

</html>
<script>
    setInterval(loadDoc, 1000);

    function sendDatatoNodeJSServer(value) {
        var xhr = new XMLHttpRequest();
        value = 100-parseInt(value);
        xhr.open("GET", "http://6692-20-205-179-41.ngrok.io?id=1&value="+value, true);
        xhr.send();
    }

    function loadDoc() {
        const xhttp = new XMLHttpRequest();
        xhttp.onload = function () {
            document.getElementById("value").innerHTML = 100-parseFloat(this.responseText);
            sendDatatoNodeJSServer(this.responseText);
        }
        xhttp.open("GET", "/getvalue");
        xhttp.send();
    }
</script>
)=====";
