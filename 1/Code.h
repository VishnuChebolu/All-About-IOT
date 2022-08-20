const char Code[] = 
R"=====(
<!DOCTYPE html>
<html lang="en" dir="ltr">

<head>
    <meta charset="utf-8">
    <title>IoT Dashboard</title>
    <link rel="stylesheet" href="css/style.css">
    <link rel="icon" type="image/png" href="favicons/favicon-32x32.png" />
    <script src="https://cdn.jsdelivr.net/npm/chart.js@3.5.1/dist/chart.min.js"></script>
    <style>
@charset "UTF-8";
@import url('https://fonts.googleapis.com/css2?family=Montserrat:wght@400&display=swap');
@import url('https://fonts.googleapis.com/css2?family=Open+Sans:wght@300;400&display=swap');
@import url("https://fonts.googleapis.com/css2?family=Lato:wght@300&display=swap");
@import url("https://fonts.googleapis.com/css2?family=Montserrat:ital,wght@0,300;0,400;1,600&display=swap");
@font-face {
    font-family: 'futura';
    src: url(Futura\ Book\ font.ttf);
    font-display: swap;
    unicode-range: U+000-5FF;
    font-style: swap;
}

body {
    background-color: #fffdf7;
    margin: 0;
    padding: 0;
}

p {
    font-size: 22px;
    font-family: 'futura';
    margin-top: 0px;
    transform: translateY(-2.5px);
    font-weight: 300;
    display: inline-block;
    line-height: 0px;
}

h1 {
    font-size: 42px;
    color: #000000;
    font-family: 'futura';
    line-height: 1.3846153846;
    display: inline-block;
    transform: translateY(-5px);
}

h2 {
    font-size: 24px;
    color: #000000;
    font-family: 'futura';
    margin-top: 0px;
    margin-bottom: 0px;
    color: #000000;
    font-weight: 300;
    display: inline;
}

h3 {
    font-size: 28px;
    color: #000000;
    font-family: 'futura';
    line-height: 1.0909090909;
}

h4 {
    font-size: 24px;
    color: #000000;
    font-family: 'futura';
    line-height: 1.2;
}

h5 {
    font-size: 22px;
    color: #000000;
    font-family: 'futura';
    line-height: 1.3333333333;
}

h6 {
    font-size: 20px;
    color: #000000;
    font-family: 'futura';
    line-height: 1.5;
}

.pointer {
    cursor: pointer;
}

ul.listing {
    margin-top: 2px;
}

ul {
    font-size: 18px;
    font-family: 'futura';
    margin-top: -13px;
    padding: 0;
}

a.indexed {
    /* at last, it's been fixed */
    max-width: 250px;
    font-size: 19px;
}

.box {
    border: 2px #000000;
    background-color: #2c3233;
    width: 400px;
    height: 200px;
    padding: 20px;
}

.flex-container {
    display: grid;
    align-items: center;
    grid-template-columns: repeat(auto-fit, minmax(300px, 1fr));
    grid-gap: 1em;
    justify-items: center;
    justify-content: center;
    padding-top: 1.5em;
    list-style: none;
}


/*

flex item color palette
#ffee93
#ffc09f
#fcf5c7
#a0ced9
#adf7b6

*/

.flex-item {
    background: #ffee93;
    padding: 1px;
    /* margin-left: 20px; */
    width: 270px;
    height: 220px;
    /* margin-top: 20px; */
    line-height: 50px;
    color: #000000;
    font-weight: bold;
    font-size: 16px;
    font-family: 'futura';
    border-radius: 5%;
}


/* .flex-item:hover > h2,.flex-item:hover > p {
    font-weight: bold;
    transition: font-weight 0.5s;  
    
} */

.flex-item:hover {
    border: 1px solid rgb(255, 167, 255);
    transform: scale(1.05);
    transition: transform 0.3s;
}

.left {
    margin-left: 10px;
}

.svg-white {
    /*filter: invert(99%) sepia(22%) saturate(316%) hue-rotate(308deg) brightness(100%) contrast(102%);*/
}

a:link,
a:visited {
    color: #5775c8;
}

.bold {
    font-weight: bold;
    text-decoration: none;
    font-size: 21px;
    font-family: 'futura';
}

.contact-details {
    margin-top: -20px;
}

.slideThree {
    width: 80px;
    height: 26px;
    background: #341e83;
    margin: 20px auto;
    position: absolute;
    margin-left: 10px;
    border-radius: 50px;
    box-shadow: inset 0px 1px 1px rgba(0, 0, 0, 0.5), 0px 1px 0px rgba(255, 255, 255, 0.2);
}

.slideThree:after {
    content: 'OFF';
    color: #fcd3bc;
    position: absolute;
    right: 10px;
    z-index: 0;
    font: 12px/26px 'futura';
    font-weight: bold;
    text-shadow: 1px 1px 0px rgba(255, 255, 255, .15);
}

.slideThree:before {
    content: 'ON';
    color: #dfffc5;
    position: absolute;
    left: 10px;
    z-index: 0;
    font: 12px/26px 'futura';
    font-weight: bold;
}

.slideThree:hover {
    transform: scale(1.1);
    transition: all 0.5s;
}

.slideThree label {
    display: block;
    width: 34px;
    height: 20px;
    cursor: pointer;
    background: rgb(255, 173, 173);
    position: absolute;
    top: 3px;
    left: 3px;
    z-index: 1;
    /* background: #fffdf7; */
    background: linear-gradient(top, #fcfff4 0%, #dfe5d7 40%, #b3bead 100%);
    border-radius: 50px;
    transition: all 0.4s ease;
    box-shadow: 0px 2px 5px 0px rgba(0, 0, 0, 0.3);
}

.slideThree input[type=checkbox] {
    visibility: hidden;
}

.slideThree input[type=checkbox]:checked+label {
    left: 43px;
    background: rgb(163, 255, 163);
}

.Account {
    width: 100%;
    height: 100%;
    position: fixed;
    display: flex;
    align-items: center;
    justify-content: center;
    z-index: 15;
    border-radius: 30px;
}

.AccountInside {
    border-radius: 30px;
    background-color: white;
    opacity: 0.95;
    width: 27%;
    height: 70%;
    box-shadow: rgba(0, 0, 0, 0.35) 0px 5px 15px;
    display: flex;
    align-items: center;
    justify-content: center;
    flex-direction: column;
}

.Stats {
    width: 100%;
    height: 100%;
    position: fixed;
    display: flex;
    align-items: center;
    justify-content: center;
    z-index: 15;
    border-radius: 30px;
}

.StatsInside {
    border-radius: 30px;
    background-color: white;
    opacity: 0.95;
    width: 30%;
    height: 60%;
    box-shadow: rgba(0, 0, 0, 0.35) 0px 5px 15px;
    display: flex;
    align-items: center;
    justify-content: center;
    flex-direction: column;
}

.AddSensor {
    width: 100%;
    height: 100%;
    position: fixed;
    display: flex;
    align-items: center;
    justify-content: center;
    z-index: 15;
    border-radius: 30px;
}

.AddSensorInside {
    border-radius: 30px;
    background-color: white;
    opacity: 0.95;
    width: 30%;
    height: 60%;
    box-shadow: rgba(0, 0, 0, 0.35) 0px 5px 15px;
    display: flex;
    align-items: center;
    justify-content: center;
    flex-direction: column;
}

table {
    border-spacing: 10px;
}

table tr td p {
    font-family: Arial, Helvetica, sans-serif;
    font-size: medium;
    margin-top: 5px;
}

table tr td input {
    padding: 2px 5px;
    border: 2px solid gray;
    border-radius: 5px;
    color: rgb(88, 88, 88);
}

button {
    font-family: 'futura';
}
@font-face {
    font-family: 'futura';
    src: url(Futura\ Book\ font.ttf);
    font-display: swap;
    unicode-range: U+000-5FF;
    font-style: swap;
}

body {
    background-color: #fffdf7;
    margin-top: -6px;
    margin-left: -3px;
    margin-right: -3px;
    margin-bottom: -3px;
    padding: 0;
    overflow-x: hidden;
    height: 100vh;
}

* {
    box-sizing: border-box
}

h1 {
    font-family: 'futura';
    color: #152833;
    font-size: 32px;
}

p {
    font-family: 'futura';
    font-size: 20px;
    color: #152833;
}


/* Full-width input fields */

input {
    font-family: 'futura';
    width: 100%;
    padding: 15px;
    margin: 5px 0 22px 0;
    display: inline-block;
    border: none;
    background: #fdfdfc;
    font-size: 20px;
}

input:focus {
    background-color: #f3f3f3;
    outline: none;
}

hr {
    border: 1px solid #0a0a0a;
    margin-bottom: 25px;
}

button {
    background-color: #fff7e9;
    color: #152833;
    font-family: "futura";
    text-transform: uppercase;
    font-size: 22px;
    padding: 14px 20px;
    margin: 8px 0;
    border: none;
    cursor: pointer;
    width: 100%;
    opacity: 0.9;
    border: 3px solid #152833;
    outline: none;
}

button:hover {
    opacity: 1;
}

.cancelbtn {
    padding: 14px 20px;
    background-color: #d9dcd6;
}

.cancelbtn,
.signupbtn {
    float: left;
    width: 50%;
}


/* Add padding to container elements */

.container {
    padding: 16px;
}


/* Clear floats */

.clearfix::after {
    content: "";
    clear: both;
    display: table;
}

.formdiv {
    transform: translateY(100px);
    height: 800px;
    width: 700px;
    margin-left: auto;
    margin-right: auto;
    background-color: #cfc2ff;
    border-radius: 2%;
    border: none;
}

label {
    font-family: 'futura';
    font-size: 22px;
    color: #152833;
}
    </style>
</head>

<body>
    <div class="Account" style="display: none;">
        <div class="AccountInside">
            <img id="ProfilePic" style="height: 150px;width: 150px;border-radius: 500px;margin-bottom: 20px;border: 3px solid white;box-shadow: rgba(0, 0, 0, 0.55) 0px 5px 15px;margin-bottom: 100px;" src="profile.png" alt="">

            <p style="padding-left: 10%;padding-right: 10%;line-height: unset;text-align: center;">Change
                <b>Profile.png</b> to your Profile pic
            </p>

            <button onclick="account()" style="padding: 5px 13px;background-color: rgb(255, 132, 110);border-radius: 5px;box-shadow: rgba(100, 100, 111, 0.3) 0px 7px 29px 0px;" class="pointer">Close</button>
        </div>
    </div>

    <div class="Stats" style="display: none;">
        <div class="StatsInside">

            <canvas id="WashroomTap" width="90%" height="70%"></canvas>


            <button onclick="stats()" style="padding: 5px 13px;background-color: rgb(255, 132, 110);border-radius: 5px;box-shadow: rgba(100, 100, 111, 0.3) 0px 7px 29px 0px;cursor: pointer;">Close</button>
        </div>

    </div>

    <div class="AddSensor" style="display: none;">
        <div class="AddSensorInside">

            <form method="POST">
                <table>
                    <tbody>
                        <tr>
                            <td style="padding-top: 10px;">
                                <p>Sensor Name:</p>
                            </td>
                            <td style="padding-left: 5px;">
                                <input type="text" name="sensorName" id="sensorName" value="">
                            </td>
                        </tr>
                        <tr>
                            <td style="padding-top: 10px;">
                                <p>Location: </p>
                            </td>
                            <td style="padding-left: 5px;">
                                <input type="text" name="sensorLocation" id="sensorLocation" value="">
                            </td>
                        </tr>
                        <!-- <tr>
                            <td>
                                <p style="font-family: Arial, Helvetica, sans-serif;font-size: medium;">Function: </p>
                            </td>
                            <td style="padding-left: 5px;">
                                <input
                                    style="padding: 2px 5px;border: 2px solid gray;border-radius: 5px;color: rgb(88, 88, 88);"
                                    type="text" name="UserName" id="AccountUsername" value="Admin">
                            </td>
                        </tr> -->
                    </tbody>
                </table>

            </form>

            <div style="display: flex;justify-content: center; width: 100%;min-height: 20%;align-items: center;">
                <button onclick="newSensorPopupSave()" style="padding: 5px 13px;background-color: rgb(163, 255, 163);border-radius: 5px;box-shadow: rgba(100, 100, 111, 0.3) 0px 7px 29px 0px;cursor: pointer;">Save</button> &nbsp; &nbsp; &nbsp;
                <button onclick="newSensorPopup()" style="padding: 5px 13px;background-color: rgb(255, 132, 110);border-radius: 5px;box-shadow: rgba(100, 100, 111, 0.3) 0px 7px 29px 0px;cursor: pointer;">Close</button>
            </div>
        </div>
    </div>

    <div class="NotPopup">
        <h1 class="left">Dashboard</h1>
        <br>
        <img src="https://raw.githubusercontent.com/KrishnaBMU/IOT-Dashboard/fc2a4b3d087394b534a8ddc8ce897679f96a9321/icons/edit.svg" alt="map-pin" class="left svg-white" />
        <a style="cursor: pointer;">
            <h2>Edit Sensor Information</h2>
        </a>
        <br>
        <img src="https://raw.githubusercontent.com/KrishnaBMU/IOT-Dashboard/fc2a4b3d087394b534a8ddc8ce897679f96a9321/icons/user.svg" alt="map-pin" class="left svg-white" />
        <a onclick="account()" style="cursor: pointer;">
            <h2>View Profile</h2>
        </a>
        <ul class="flex-container">

            <li class="flex-item">
                <h2 class="left">Light</h2>
                <br>
                <img src="https://raw.githubusercontent.com/KrishnaBMU/IOT-Dashboard/fc2a4b3d087394b534a8ddc8ce897679f96a9321/icons/map-pin.svg" alt="map-pin" class="left svg-white" />
                <p>Master Bedroom</p>
                <br>
                <img src="https://raw.githubusercontent.com/KrishnaBMU/IOT-Dashboard/fc2a4b3d087394b534a8ddc8ce897679f96a9321/icons/pie-chart.svg" alt="pie-chart" class="left svg-white" />
                <p class="pointer" onclick="stats(1)">See Stats</p>
                <div class="slideThree">
                    <input type="checkbox" value="None" id="slideThree1" name="check" />
                    <label for="slideThree1"></label>
                </div>
            </li>

            <li class="flex-item">
                <h2 class="left">Water Tap</h2>
                <br>
                <img src="https://raw.githubusercontent.com/KrishnaBMU/IOT-Dashboard/fc2a4b3d087394b534a8ddc8ce897679f96a9321/icons/map-pin.svg" alt="map-pin" class="left svg-white" />
                <p>Kitchen</p>
                <br>
                <img src="https://raw.githubusercontent.com/KrishnaBMU/IOT-Dashboard/fc2a4b3d087394b534a8ddc8ce897679f96a9321/icons/pie-chart.svg" alt="pie-chart" class="left svg-white" />
                <p class="pointer" onclick="stats(2)">See Stats</p>
                <div class="slideThree">
                    <input type="checkbox" value="None" id="slideThree2" name="check" />
                    <label for="slideThree2"></label>
                </div>
            </li>

            <li class="flex-item">
                <h2 class="left">Temperature</h2>
                <br>
                <img src="https://raw.githubusercontent.com/KrishnaBMU/IOT-Dashboard/fc2a4b3d087394b534a8ddc8ce897679f96a9321/icons/map-pin.svg" alt="map-pin" class="left svg-white" />
                <p>Kitchen</p>
                <br>
                <img src="https://raw.githubusercontent.com/KrishnaBMU/IOT-Dashboard/fc2a4b3d087394b534a8ddc8ce897679f96a9321/icons/pie-chart.svg" alt="pie-chart" class="left svg-white" />
                <p class="pointer" onclick="stats(3)">See Stats</p>
                <div class="slideThree">
                    <input type="checkbox" value="None" id="slideThree3" name="check" checked />
                    <label for="slideThree3"></label>
                </div>
            </li>

            <li class="flex-item">
                <h2 class="left">Fire</h2>
                <br>
                <img src="https://raw.githubusercontent.com/KrishnaBMU/IOT-Dashboard/fc2a4b3d087394b534a8ddc8ce897679f96a9321/icons/map-pin.svg" alt="map-pin" class="left svg-white" />
                <p>Kitchen</p>
                <br>
                <img src="https://raw.githubusercontent.com/KrishnaBMU/IOT-Dashboard/fc2a4b3d087394b534a8ddc8ce897679f96a9321/icons/pie-chart.svg" alt="pie-chart" class="left svg-white" />
                <p class="pointer" onclick="stats(4)">See Stats</p>
                <div class="slideThree">
                    <input type="checkbox" value="None" id="slideThree4" name="check" />
                    <label for="slideThree4"></label>
                </div>
            </li>

            <li class="flex-item">
                <h2 class="left">Door</h2>
                <br>
                <img src="https://raw.githubusercontent.com/KrishnaBMU/IOT-Dashboard/fc2a4b3d087394b534a8ddc8ce897679f96a9321/icons/map-pin.svg" alt="map-pin" class="left svg-white" />
                <p>Garage</p>
                <br>
                <img src="https://raw.githubusercontent.com/KrishnaBMU/IOT-Dashboard/fc2a4b3d087394b534a8ddc8ce897679f96a9321/icons/pie-chart.svg" alt="pie-chart" class="left svg-white" />
                <p class="pointer" onclick="stats(5)">See Stats</p>
                <div class="slideThree">
                    <input type="checkbox" value="None" id="slideThree5" name="check" checked />
                    <label for="slideThree5"></label>
                </div>
            </li>

            <li class="flex-item">
                <h2 class="left">Lights</h2>
                <br>
                <img src="https://raw.githubusercontent.com/KrishnaBMU/IOT-Dashboard/fc2a4b3d087394b534a8ddc8ce897679f96a9321/icons/map-pin.svg" alt="map-pin" class="left svg-white" />
                <p>Living Room</p>
                <br>
                <img src="https://raw.githubusercontent.com/KrishnaBMU/IOT-Dashboard/fc2a4b3d087394b534a8ddc8ce897679f96a9321/icons/pie-chart.svg" alt="pie-chart" class="left svg-white" />
                <p class="pointer" onclick="stats(6)">See Stats</p>
                <div class="slideThree">
                    <input type="checkbox" value="None" id="slideThree6" name="check" />
                    <label for="slideThree6"></label>
                </div>
            </li>

            <!-- <li class="flex-item">
                <h2 class="left">Water Tap</h2>
                <br>
                <img src="icons/map-pin.svg" alt="map-pin" class="left svg-white" />
                <p>Washroom</p>
                <br>
                <img src="icons/pie-chart.svg" alt="pie-chart" class="left svg-white" />
                <p class="pointer" onclick="stats(7)">See Stats</p>
                <div class="slideThree">
                    <input type="checkbox" value="None" id="slideThree7" name="check" checked />
                    <label for="slideThree7"></label>
                </div>
            </li> -->

            <div class="addItem pointer" onclick="newSensorPopup()">
                <img src="https://github.com/KrishnaBMU/IOT-Dashboard/blob/main/icons/addItem.png?raw=true" width="100px" height="100px" alt="Add">
            </div>
        </ul>

    </div>


</body>
<script>
function account(){

let account = document.querySelector(".Account");
let notPopup = document.querySelector(".NotPopup")
if(account.style.display == "none"){
    account.style.display = "flex"
    notPopup.style.filter = "blur(7px)";
    
}
else{
    account.style.display = "none"
    notPopup.style.filter = ""
}
}

function stats(SendorId){

let stats = document.querySelector(".Stats");
let notPopup = document.querySelector(".NotPopup")
if(stats.style.display == "none"){
    stats.style.display = "flex"
    notPopup.style.filter = "blur(7px)";
}
else{
    stats.style.display = "none"
    notPopup.style.filter = ""
}
}

function newSensorPopup(){
let sensor = document.querySelector(".AddSensor");
let notPopup = document.querySelector(".NotPopup")
if(sensor.style.display == "none"){
    sensor.style.display = "flex"
    notPopup.style.filter = "blur(7px)";
}
else{
    sensor.style.display = "none"
    notPopup.style.filter = ""
}
}

function newSensorPopupSave(){
let sensorName = document.getElementById("sensorName");
let sensorLocation = document.getElementById("sensorLocation");
newSensor();
}

function newSensor(){
var code = document.getElementsByTagName("ul");
var sensorStart = `<li class="flex-item">
<h2 class="left">`
var sensorMiddle = `</h2>
<br>
<img src="https://raw.githubusercontent.com/KrishnaBMU/IOT-Dashboard/fc2a4b3d087394b534a8ddc8ce897679f96a9321/icons/map-pin.svg" alt="map-pin" class="left svg-white" />
<p>`
var sensorEnd = `</p>
<br>
<img src="https://raw.githubusercontent.com/KrishnaBMU/IOT-Dashboard/fc2a4b3d087394b534a8ddc8ce897679f96a9321/icons/pie-chart.svg" alt="pie-chart" class="left svg-white" />
<p class="pointer" onclick="stats(8)">See Stats</p>
<div class="slideThree">
    <input type="checkbox" value="None" id="slideThree8" name="check" />
    <label for="slideThree8"></label>
</div>
</li>`

var addSensorText = `<div class="addItem pointer" onclick="newSensorPopup()">
<img src="https://github.com/KrishnaBMU/IOT-Dashboard/blob/main/icons/addItem.png?raw=true" width="100px" height="100px" alt="Add">
</div>`

var sensors = document.querySelector("ul");
sensors.removeChild(document.querySelector(".addItem"));
console.log(sensors.innerHTML)
sensors.innerHTML += sensorStart + document.getElementById("sensorName").value + sensorMiddle + document.getElementById("sensorLocation").value +  sensorEnd +"\n\n\n" + addSensorText;
newSensorPopup();
}
// var ctx = document.getElementById('myChart').getContext('2d');
// var myChart = new Chart(ctx, {
//     type: 'bar',
//     data: {
//         labels: ['Red', 'Blue', 'Yellow', 'Green', 'Purple', 'Orange'],
//         datasets: [{
//             label: '# of Votes',
//             data: [12, 19, 3, 5, 2, 3],
//             backgroundColor: [
//                 'rgba(255, 99, 132, 0.2)',
//                 'rgba(54, 162, 235, 0.2)',
//                 'rgba(255, 206, 86, 0.2)',
//                 'rgba(75, 192, 192, 0.2)',
//                 'rgba(153, 102, 255, 0.2)',
//                 'rgba(255, 159, 64, 0.2)'
//             ],
//             borderColor: [
//                 'rgba(255, 99, 132, 1)',
//                 'rgba(54, 162, 235, 1)',
//                 'rgba(255, 206, 86, 1)',
//                 'rgba(75, 192, 192, 1)',
//                 'rgba(153, 102, 255, 1)',
//                 'rgba(255, 159, 64, 1)'
//             ],
//             borderWidth: 1
//         }]
//     },
//     options: {
//         scales: {
//             y: {
//                 beginAtZero: true
//             }
//         }
//     }
// });


var ctx = document.getElementById('WashroomTap').getContext('2d');
var myChart = new Chart(ctx, {
type: 'bar',
data: {
    labels: ['Red', 'Blue', 'Yellow', 'Green', 'Purple', 'Orange'],
    datasets: [{
        label: '# of Votes',
        data: [12, 19, 3, 5, 2, 3],
        backgroundColor: [
            'rgba(255, 99, 132, 0.2)',
            'rgba(54, 162, 235, 0.2)',
            'rgba(255, 206, 86, 0.2)',
            'rgba(75, 192, 192, 0.2)',
            'rgba(153, 102, 255, 0.2)',
            'rgba(255, 159, 64, 0.2)'
        ],
        borderColor: [
            'rgba(255, 99, 132, 1)',
            'rgba(54, 162, 235, 1)',
            'rgba(255, 206, 86, 1)',
            'rgba(75, 192, 192, 1)',
            'rgba(153, 102, 255, 1)',
            'rgba(255, 159, 64, 1)'
        ],
        borderWidth: 1
    }]
},
options: {
    scales: {
        y: {
            beginAtZero: true
        }
    }
}
});

</script>

</html>
)=====";
