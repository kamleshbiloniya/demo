<!doctype html>
<html lang="en">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<title>Cam Snap</title>
<script type="text/javascript" src="webcam.js"></script>
<script language="JavaScript">
var count = 0;
function take_snapshot() {
    Webcam.snap(function(data_uri) {
    document.getElementById('results').innerHTML = '<img id="base64image" src="'+data_uri+'"/>';
    SaveSnap();
});

}
var myVar ;
function myStartFunction() {
    myVar = setInterval(take_snapshot,1000);
}
function myStopFunction() {
    clearInterval(myVar);
}

function ShowCam(){
Webcam.set({
width: 320,
height: 240,
image_format: 'jpeg',
jpeg_quality: 100
});
Webcam.attach('#my_camera');
}


function SaveSnap(){
    document.getElementById("loading").innerHTML="Saving, please wait...";
    var file =  document.getElementById("base64image").src;
    var formdata = new FormData();
    formdata.append("base64image", file);
    formdata.append("count",count);
    var ajax = new XMLHttpRequest();
    ajax.addEventListener("load", function(event) { uploadcomplete(event);}, false);
    ajax.open("POST", "upload.php");
    ajax.send(formdata);
    count = count + 1;

}
function uploadcomplete(event){
    document.getElementById("loading").innerHTML="";
    var image_return=event.target.responseText;
    var showup=document.getElementById("uploaded").src=image_return;
}
window.onload= ShowCam;
</script>
<style type="text/css">
.container{display:inline-block;width:320px;}
#Cam{background:rgb(255,255,215);}#Prev{background:rgb(255,255,155);}#Saved{background:rgb(255,255,55);}
</style>
</head>
<body>
  <p id="demo"></p>
  <div class="container" id="Cam"><b>Webcam Preview...</b>
      <div id="my_camera"></div><form><input type="button" value="Start" onClick="myStartFunction()"></form>
      <div id="my_camera"></div><form><input type="button" value="stop" onClick="myStopFunction()"></form>
  </div>

<div class="container" id="Prev">
    <b>Snap Preview...</b><div id="results"></div>
</div>
<div class="container" id="Saved">
    <b>Saved</b><span id="loading"></span><img id="uploaded" src=""/>
</div>
<br><br><br>
<a href="0.txt">see output file</a>
<br><br>
<a href="webcam">see images</a>
</body>
</html>
