const char Code[] = 
R"=====(
<!DOCTYPE html>
<html lang="en" dir="ltr">

<head>
    <meta charset="utf-8">
    <title>IoT Dashboard</title>
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

        .EditSensor {
            width: 100%;
            height: 100%;
            position: fixed;
            display: flex;
            align-items: center;
            justify-content: center;
            z-index: 15;
            border-radius: 30px;
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

        /* button {
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
        } */

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

        /* Button Style */
        .pushable {
            background: hsl(340deg 100% 32%);
            border: none;
            border-radius: 12px;
            padding: 0;
            cursor: pointer;
        }

        .front {
            display: block;
            padding: 12px 42px;
            border-radius: 12px;
            font-size: 1.25rem;
            background: hsl(345deg 100% 47%);
            color: white;
            transform: translateY(-4px);
        }

        .pushable:focus:not(:focus-visible) {
            outline: none;
        }


        /* Chat Bot Styling */
        body {
            font-family: Arial, Helvetica, sans-serif;
        }

        * {
            box-sizing: border-box;
        }


        .open-button {
            /* background-color: #555;
            color: white;
            padding: 16px 20px;
            border: none;
            cursor: pointer;
            opacity: 0.8; */
            position: fixed;
            bottom: 23px;
            right: 28px;
            width: 280px;
        }


        .chat-popup {
            display: none;
            position: fixed;
            bottom: 0;
            right: 15px;
            border-radius: 20px;
            border: 5px solid #f1f1f1;
            z-index: 9;
        }

        /* Add styles to the form container */
        .form-container {
            max-width: 300px;
            padding: 10px;
            border-radius: 20px;
            background-color: white;
        }

        /* Full-width textarea */
        .form-container textarea {
            width: 100%;
            padding: 15px;
            margin: 5px 0 22px 0;
            border: none;
            background: #f1f1f1;
            resize: none;
            min-height: 100px;
        }

        /* When the textarea gets focus, do something */
        .form-container textarea:focus {
            background-color: #ddd;
            outline: none;
        }

        /* Set a style for the submit/send button */
        .form-container .btn {
            background-color: #04AA6D;
            color: white;
            padding: 16px 20px;
            border: none;
            cursor: pointer;
            width: 100%;
            margin-bottom: 10px;
            opacity: 0.8;
        }

        /* Add a red background color to the cancel button */
        .form-container .cancel {
            background-color: red;
        }

        /* Add some hover effects to buttons */
        .form-container .btn:hover,
        .open-button:hover {
            opacity: 1;
        }
    </style>
</head>

<body>
    <div class="Account" style="display:none">
        <div class="AccountInside">

            <table>
                <tr>
                    <td style="padding-top: 10px;">
                        <p>Profile url:</p>
                    </td>
                    <td style="padding-left: 5px;">
                        <input type="text" id="profileUrl" value="">
                    </td>
                </tr>
            </table>

            <img id="ProfilePic"
                style="height: 150px;width: 150px;border-radius: 500px;margin-bottom: 20px;border: 3px solid white;box-shadow: rgba(0, 0, 0, 0.55) 0px 5px 15px;margin-bottom: 100px;"
                src="https://1.bp.blogspot.com/-0ZUMPsBahSo/X0vuBttwtWI/AAAAAAAAdwM/_0Nuxi-PWUsgTsLdAmGZqILPiJf7N2bdACLcBGAsYHQ/s640/best%2Bdp%2Bfor%2Bwhatsapp%2B%25281%2529.jpg" alt="">

            <p style="padding-left: 10%;padding-right: 10%;line-height: unset;text-align: center;">Change
                <b>Profile.png</b> to your Profile pic
            </p>

            <div style="display: flex;justify-content: center; width: 100%;min-height: 20%;align-items: center;">
                <button onclick="profileSave()"
                    style="margin: 10%; padding: 5px 13px;background-color: rgb(163, 255, 163);border-radius: 5px;box-shadow: rgba(100, 100, 111, 0.3) 0px 7px 29px 0px;cursor: pointer;">Save</button>

                <button onclick="account()"
                    style="padding: 5px 13px;background-color: rgb(255, 132, 110);border-radius: 5px;box-shadow: rgba(100, 100, 111, 0.3) 0px 7px 29px 0px;"
                    class="pointer">Close</button>
            </div>

        </div>
    </div>

    <div class="Stats" style="display: none;">
        <div class="StatsInside">

            <iframe src="" id="iframe1" width="100%" height="40%"></iframe>


            <button onclick="stats()"
                style="padding: 5px 13px;background-color: rgb(255, 132, 110);border-radius: 5px;box-shadow: rgba(100, 100, 111, 0.3) 0px 7px 29px 0px;cursor: pointer;">Close</button>
        </div>

    </div>

    <div class="EditSensor" style="display: none;">
        <div class="AddSensorInside">

            <form method="POST">
                <table>
                    <tbody>
                        <tr>
                            <td style="padding-top: 10px;">
                                <p>Sensor Id:</p>
                            </td>
                            <td style="padding-top: 5px;">
                                <!-- <input type="list" list="editSensorSelect"/> -->
                                <select id="editSensorSelect">
                                    <option value="1" selected>1</option>
                                    <option value="2">2</option>
                                    <option value="3">3</option>
                                    <option value="4">4</option>
                                    <option value="5">5</option>
                                    <option value="6">6</option>
                                </select>
                            </td>
                        </tr>
                        <tr>
                            <td style="padding-top: 10px;">
                                <p>Sensor Name:</p>
                            </td>
                            <td style="padding-left: 5px;">
                                <input type="text" name="sensorName" id="editSensorName" value="">
                            </td>
                        </tr>
                        <tr>
                            <td style="padding-top: 10px;">
                                <p>Location: </p>
                            </td>
                            <td style="padding-left: 5px;">
                                <input type="text" name="sensorLocation" id="editSensorLocation" value="">
                            </td>
                        </tr>
                    </tbody>
                </table>

            </form>

            <div style="display: flex;justify-content: center; width: 100%;min-height: 20%;align-items: center;">
                <button onclick="editSensorPopupSave()"
                    style="margin: 10%; padding: 5px 13px;background-color: rgb(163, 255, 163);border-radius: 5px;box-shadow: rgba(100, 100, 111, 0.3) 0px 7px 29px 0px;cursor: pointer;">Save</button>
                &nbsp; &nbsp; &nbsp;
                <button onclick="editSensorPopup()"
                    style="margin: 10%; padding: 5px 13px;background-color: rgb(255, 132, 110);border-radius: 5px;box-shadow: rgba(100, 100, 111, 0.3) 0px 7px 29px 0px;cursor: pointer;">Close</button>
            </div>
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
                        <tr>
                            <td style="padding-top: 10px;">
                                <p>Pin number: </p>
                            </td>
                            <td style="padding-left: 5px;">
                                <p id="pinnum"></p>
                            </td>
                        </tr>
                    </tbody>
                </table>

            </form>

            <div style="display: flex;justify-content: center; width: 100%;min-height: 20%;align-items: center;">
                <button onclick="newSensorPopupSave()"
                    style="margin: 10%; padding: 5px 13px;background-color: rgb(163, 255, 163);border-radius: 5px;box-shadow: rgba(100, 100, 111, 0.3) 0px 7px 29px 0px;cursor: pointer;">Save</button>
                &nbsp; &nbsp; &nbsp;
                <button onclick="newSensorPopup()"
                    style="margin: 10%; padding: 5px 13px;background-color: rgb(255, 132, 110);border-radius: 5px;box-shadow: rgba(100, 100, 111, 0.3) 0px 7px 29px 0px;cursor: pointer;">Close</button>
            </div>
        </div>
    </div>

    <div class="NotPopup">
        <h1 class="left">Dashboard</h1>
        <br>
        <img src="https://raw.githubusercontent.com/KrishnaBMU/IOT-Dashboard/fc2a4b3d087394b534a8ddc8ce897679f96a9321/icons/edit.svg"
            alt="map-pin" class="left svg-white" />
        <a onclick="editSensorPopup()" style="cursor: pointer;">
            <h2>Edit Sensor Information</h2>
        </a>
        <br>
        <img src="https://raw.githubusercontent.com/KrishnaBMU/IOT-Dashboard/fc2a4b3d087394b534a8ddc8ce897679f96a9321/icons/user.svg"
            alt="map-pin" class="left svg-white" />
        <a onclick="account()" style="cursor: pointer;">
            <h2>View Profile</h2>
        </a>
        <ul class="flex-container">

            <li class="flex-item">
                <h2 id="deviceName1" class="left">Light</h2>
                <br>
                <img src="https://raw.githubusercontent.com/KrishnaBMU/IOT-Dashboard/fc2a4b3d087394b534a8ddc8ce897679f96a9321/icons/map-pin.svg"
                    alt="map-pin" class="left svg-white" />
                <p id="deviceLocation1">Master Bedroom</p>
                <br>
                <img src="https://raw.githubusercontent.com/KrishnaBMU/IOT-Dashboard/fc2a4b3d087394b534a8ddc8ce897679f96a9321/icons/pie-chart.svg"
                    alt="pie-chart" class="left svg-white" />
                <p class="pointer" onclick="stats(1)">See Stats</p>
                <div class="slideThree">
                    <input type="checkbox" value="None" id="slideThree1" onchange="checkbox()" name="check" />
                    <label for="slideThree1"></label>
                </div>
            </li>

            <li class="flex-item">
                <h2 id="deviceName2" class="left">Water Tap</h2>
                <br>
                <img src="https://raw.githubusercontent.com/KrishnaBMU/IOT-Dashboard/fc2a4b3d087394b534a8ddc8ce897679f96a9321/icons/map-pin.svg"
                    alt="map-pin" class="left svg-white" />
                <p id="deviceLocation2">Kitchen</p>
                <br>
                <img src="https://raw.githubusercontent.com/KrishnaBMU/IOT-Dashboard/fc2a4b3d087394b534a8ddc8ce897679f96a9321/icons/pie-chart.svg"
                    alt="pie-chart" class="left svg-white" />
                <p class="pointer" onclick="stats(2)">See Stats</p>
                <div class="slideThree">
                    <input type="checkbox" value="None" id="slideThree2" onchange="checkbox()" name="check" />
                    <label for="slideThree2"></label>
                </div>
            </li>

            <li class="flex-item">
                <h2 id="deviceName3" class="left">Temperature</h2>
                <br>
                <img src="https://raw.githubusercontent.com/KrishnaBMU/IOT-Dashboard/fc2a4b3d087394b534a8ddc8ce897679f96a9321/icons/map-pin.svg"
                    alt="map-pin" class="left svg-white" />
                <p id="deviceLocation3">Kitchen</p>
                <br>
                <img src="https://raw.githubusercontent.com/KrishnaBMU/IOT-Dashboard/fc2a4b3d087394b534a8ddc8ce897679f96a9321/icons/pie-chart.svg"
                    alt="pie-chart" class="left svg-white" />
                <p class="pointer" onclick="stats(3)">See Stats</p>
                <div class="slideThree">
                    <input type="checkbox" value="None" id="slideThree3" onchange="checkbox()" name="check" />
                    <label for="slideThree3"></label>
                </div>
            </li>

            <li class="flex-item">
                <h2 id="deviceName4" class="left">Fire</h2>
                <br>
                <img src="https://raw.githubusercontent.com/KrishnaBMU/IOT-Dashboard/fc2a4b3d087394b534a8ddc8ce897679f96a9321/icons/map-pin.svg"
                    alt="map-pin" class="left svg-white" />
                <p id="deviceLocation4">Kitchen</p>
                <br>
                <img src="https://raw.githubusercontent.com/KrishnaBMU/IOT-Dashboard/fc2a4b3d087394b534a8ddc8ce897679f96a9321/icons/pie-chart.svg"
                    alt="pie-chart" class="left svg-white" />
                <p class="pointer" onclick="stats(4)">See Stats</p>
                <div class="slideThree">
                    <input type="checkbox" value="None" id="slideThree4" onchange="checkbox()" name="check" />
                    <label for="slideThree4"></label>
                </div>
            </li>

            <li class="flex-item">
                <h2 id="deviceName5" class="left">Door</h2>
                <br>
                <img src="https://raw.githubusercontent.com/KrishnaBMU/IOT-Dashboard/fc2a4b3d087394b534a8ddc8ce897679f96a9321/icons/map-pin.svg"
                    alt="map-pin" class="left svg-white" />
                <p id="deviceLocation5">Garage</p>
                <br>
                <img src="https://raw.githubusercontent.com/KrishnaBMU/IOT-Dashboard/fc2a4b3d087394b534a8ddc8ce897679f96a9321/icons/pie-chart.svg"
                    alt="pie-chart" class="left svg-white" />
                <p class="pointer" onclick="stats(5)">See Stats</p>
                <div class="slideThree">
                    <input type="checkbox" value="None" id="slideThree5" onchange="checkbox()" name="check" />
                    <label for="slideThree5"></label>
                </div>
            </li>

            <li class="flex-item">
                <h2 id="deviceName6" class="left">Lights</h2>
                <br>
                <img src="https://raw.githubusercontent.com/KrishnaBMU/IOT-Dashboard/fc2a4b3d087394b534a8ddc8ce897679f96a9321/icons/map-pin.svg"
                    alt="map-pin" class="left svg-white" />
                <p id="deviceLocation6">Living Room</p>
                <br>
                <img src="https://raw.githubusercontent.com/KrishnaBMU/IOT-Dashboard/fc2a4b3d087394b534a8ddc8ce897679f96a9321/icons/pie-chart.svg"
                    alt="pie-chart" class="left svg-white" />
                <p class="pointer" onclick="stats(6)">See Stats</p>
                <div class="slideThree">
                    <input type="checkbox" value="None" id="slideThree6" onchange="checkbox()" name="check" />
                    <label for="slideThree6"></label>
                </div>
            </li>


            <div class="addItem pointer" onclick="newSensorPopup()">
                <img src="https://github.com/KrishnaBMU/IOT-Dashboard/blob/main/icons/addItem.png?raw=true"
                    width="100px" height="100px" alt="Add">
            </div>
        </ul>



        <style>
            .front {
                will-change: transform;
                transition: transform 250ms;
            }

            .pushable:hover .front {
                transform: translateY(-6px);
            }

            .pushable:active .front {
                transform: translateY(-2px);
            }
        </style>

        <button class="pushable open-button" onclick="openForm()">
            <span class="front">
                Chat
            </span>
        </button>
        <!-- <button class="open-button">Chat</button> -->

        <div class="chat-popup" id="myForm">
            <div class="form-container">
                <h1>Chat</h1>

                <label for="msg"></label>
                <input id="ChatbotText" rows="1" placeholder="Type message..." onkeypress="keyPress()"
                    name="msg"></input>
                <textarea id="ChatbotTextOutput" style="cursor: text;user-select: none;padding: 10px;"
                    placeholder="Output..." readonly></textarea>

                <button class="pushable" id="chatSend" style="background-color: #087e49;" onclick="sendForm()">
                    <span class="front" style="background-color: #04AA6D;">
                        Send
                    </span>
                </button>
                <button class="pushable" onclick="closeForm()">
                    <span class="front">
                        close
                    </span>
                </button>
            </div>
        </div>

</body>
<script>

    let number = 6;

    function account() {

        let account = document.querySelector(".Account");
        let notPopup = document.querySelector(".NotPopup")
        if (account.style.display == "none") {
            account.style.display = "flex"
            notPopup.style.filter = "blur(7px)";

        }
        else {
            account.style.display = "none"
            notPopup.style.filter = ""
        }
    }

    function profileSave(){
        document.getElementById("ProfilePic").src = document.getElementById("profileUrl").value;
        document.getElementById("profileUrl").value = "";
        account();
    }

    function stats(SendorId) {

        let link = "https://thingspeak.com/channels/1526741/charts/" + SendorId + "?bgcolor=%23ffffff&color=%23d62020&dynamic=true&results=60&type=line&update=15"

        let stats = document.querySelector(".Stats");
        let notPopup = document.querySelector(".NotPopup")
        if (stats.style.display == "none") {
            stats.style.display = "flex"
            notPopup.style.filter = "blur(7px)";
            let graph = document.getElementById("iframe1");
            graph['src'] = link;
        }
        else {
            stats.style.display = "none"
            notPopup.style.filter = ""
        }
    }

    function newSensorPopup() {
        let sensor = document.querySelector(".AddSensor");
        let notPopup = document.querySelector(".NotPopup")
        if (sensor.style.display == "none") {
            sensor.style.display = "flex"
            notPopup.style.filter = "blur(7px)";
            if (number < 8) {
                document.getElementById("pinnum").innerHTML = 'D' + (number);
            }
            else {
                document.getElementById("pinnum").innerHTML = "No more pins available";
            }

        }
        else {
            sensor.style.display = "none"
            notPopup.style.filter = ""
        }
    }

    function newSensorPopupSave() {
        let sensorName = document.getElementById("sensorName");
        let sensorLocation = document.getElementById("sensorLocation");
        newSensor();
        number = number + 1;
    }

    function newSensor() {
        var code = document.getElementsByTagName("ul");
        var sensorStart = `<li class="flex-item">
<h2 id="deviceName` + (number + 1) + `"class="left">`
        var sensorMiddle = `</h2>
<br>
<img src="https://raw.githubusercontent.com/KrishnaBMU/IOT-Dashboard/fc2a4b3d087394b534a8ddc8ce897679f96a9321/icons/map-pin.svg" alt="map-pin" class="left svg-white" />
<p id="deviceLocation` + (number + 1) + `">`
        var sensorEnd = `</p>
<br>
<img src="https://raw.githubusercontent.com/KrishnaBMU/IOT-Dashboard/fc2a4b3d087394b534a8ddc8ce897679f96a9321/icons/pie-chart.svg" alt="pie-chart" class="left svg-white" />
<p class="pointer" onclick="stats(`+ number + `)">See Stats</p>
<div class="slideThree">
    <input type="checkbox" value="None" id="slideThree` + number + `" onchange="checkbox()" name="check" />
    <label for="slideThree` + number + `"></label>
</div>
</li>`

        var addSensorText = `<div class="addItem pointer" onclick="newSensorPopup()">
<img src="https://github.com/KrishnaBMU/IOT-Dashboard/blob/main/icons/addItem.png?raw=true" width="100px" height="100px" alt="Add">
</div>`

        var sensors = document.querySelector("ul");
        sensors.removeChild(document.querySelector(".addItem"));
        console.log(sensors.innerHTML)
        sensors.innerHTML += sensorStart + document.getElementById("sensorName").value + sensorMiddle + document.getElementById("sensorLocation").value + sensorEnd + "\n\n\n" + addSensorText;

        let newSelect = document.createElement("option");
        newSelect.value = number + 1
        newSelect.innerHTML = number + 1
        document.getElementById("editSensorSelect").append(newSelect)

        newSensorPopup();
    }

    function send(link) {
        var xhttp = new XMLHttpRequest();
        // xhttp.onreadystatechange = function () {
        //     if (this.readyState == 4 && this.status == 200) {
        //         document.getElementById("state").innerHTML = this.responseText;
        //     }
        // };
        console.log(link);
        xhttp.open("GET", link, true);
        xhttp.send();
    }

    var option1 = document.getElementById("slideThree1");
    var option2 = document.getElementById("slideThree2");
    var option3 = document.getElementById("slideThree3");
    var option4 = document.getElementById("slideThree4");
    var option5 = document.getElementById("slideThree5");
    var option6 = document.getElementById("slideThree6");
    // var option7 = document.getElementById("slideThree7");
    let a = "0";
    let b = "0";
    let c = "0";
    let d = "0";
    let e = "0";
    let f = "0";
    // let g = "0";
    function checkbox() {

        if (option1.checked) {
            a = "1";
        }
        else if (!option1.checked) {
            a = "0";
        }
        if (option2.checked) {
            b = "1";
        }
        else if (!option2.checked) {
            b = "0";
        }
        if (option3.checked) {
            c = "1";
        }
        else if (!option3.checked) {
            c = "0";
        }
        if (option4.checked) {
            d = "1";
        }
        else if (!option4.checked) {
            d = "0";
        }
        if (option5.checked) {
            e = "1";
        }
        else if (!option5.checked) {
            e = "0";
        }
        if (option6.checked) {
            f = "1";
        }
        else if (!option6.checked) {
            f = "0";
        }
        // if (option7.checked) {
        //     g = "1";
        // }
        // else if (!option7.checked) {
        //     g = "0";
        // }
        let link = "https://api.thingspeak.com/update?api_key=Z23ESCW35RJN0OFD&field1=" + a + "&field2=" + b + "&field3=" + c + "&field4=" + d + "&field5=" + e + "&field6=" + f;
        send(link);
    }


    function openForm() {
        document.getElementById("myForm").style.display = "block";
    }

    function closeForm() {
        document.getElementById("myForm").style.display = "none";
        document.getElementById("ChatbotText").value = "";
        document.getElementById("ChatbotTextOutput").value = "";
    }

    function keyPress(event) {
        if (window.event.keyCode == 13) {
            sendForm();
        }
    }


    function sendForm() {
        const chat = document.getElementById("ChatbotText");
        const chatOutput = document.getElementById("ChatbotTextOutput");
        const chatText = chat.value;
        let chatArray = chatText.split(" ")
        try {
            var box = document.getElementById("slideThree" + chatArray[1]);
            if (chatArray[0] == "on") {
                box.checked = true;
                chatOutput.value = "\nswitched " + chat.value
            }
            else if (chatArray[0] == "off") {
                box.checked = false;
                chatOutput.value = "\nswitched " + chat.value
            }
            else if (chatArray[0] == "help") {

                str = `Hello master!
I am here to help you.

Here are my commands - 
1. help
2. on/off deviceID
3. numOf on
4. numOf off      
5. stats deviceID  
`
                chatOutput.value = str
            }
            else if (chatArray[0] == "numOf") {
                if (chatArray[1] == "on") {
                    chatOutput.value = "There are " + countOn() + " devices on";
                    console.log(countOn());
                }
                if (chatArray[1] == "off") {
                    chatOutput.value = "There are " + countOff() + " devices off";
                    console.log(countOff());
                }

            }
            else if (chatArray[0] == "stats") {
                stats(chatArray[1])
            }
            else if (chatArray[0] == "profile") {
                account()

            }
            else {
                chatOutput = chat.value;
            }
        } catch (error) {
            console.log(error);
        }

        checkbox();
        chat.value = "";

    }

    function countOn() {
        let count = 0;
        for (i = 1; i < number; i++) {
            temp = document.getElementById("slideThree" + i);
            if (temp.checked) {
                count = count + 1
            }
        }
        return count;
    }

    function countOff() {
        let count = 0;
        for (i = 1; i < number; i++) {
            temp = document.getElementById("slideThree" + i);
            if (!temp.checked) {
                count = count + 1
            }
        }
        return count;
    }

    function editSensorPopup() {
        let sensor = document.querySelector(".EditSensor");
        let notPopup = document.querySelector(".NotPopup")
        if (sensor.style.display == "none") {
            sensor.style.display = "flex"
            notPopup.style.filter = "blur(7px)";
        }
        else {
            sensor.style.display = "none"
            notPopup.style.filter = ""
        }
    }
    function editSensorPopupSave() {
        let editSensorSelect = document.getElementById("editSensorSelect");
        let editSensorName = document.getElementById("editSensorName");
        let editSensorLocation = document.getElementById("editSensorLocation");

        let sensorName = document.getElementById("deviceName" + editSensorSelect.value);
        let sensorLocation = document.getElementById("deviceLocation" + editSensorSelect.value)

        sensorName.innerHTML = editSensorName.value;
        sensorLocation.innerHTML = editSensorLocation.value;
        editSensorPopup();
    }

</script>

</html>
)=====";
