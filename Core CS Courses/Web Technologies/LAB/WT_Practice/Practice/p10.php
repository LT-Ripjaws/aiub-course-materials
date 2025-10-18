<!DOCTYPE html>
<html>
<body>

<title> Changing  </title>

<style>

body{

font-family:"Arial, Helvetica, sans-serif";
text-align: center;
padding : 20px;

}

#switchbutton{
padding: 10px,20px;
font-size: 15px;
cursor: pointer;

}


</style>


<h1 id="pagetitle" > Light Mood </h1>

<button id ="switchbutton" onclick="toggle()"> Switch </button>

<script>

function toggle()
{

var body = document.body;
var title = document.getElementById("pagetitle");
var button = document.getElementById("switchbutton");


if (body.style.backgroundColor === "black")
{

body.style.backgroundColor ="white";
body.style.color="black";
title.innerHTML="Light Mode";
button.innerHTML= "Swtich to Dark Mood";

}

else {

body.style.backgroundColor ="black";
body.style.color="white";
title.innerHTML="Dark Mode";
button.innerHTML= "Swtich to Light Mood";

}


}


</script>