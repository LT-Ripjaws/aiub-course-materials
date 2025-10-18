<!DOCTYPE html>

<html>

<body>

<h1 id="new" > "This is the JS Intro class" </h1>

<h2 id="new2">" "</h2> 

<p id="para">  Today we will learn about Dom and form validation </p>

<button onclick="greet()"> click me </button>
<script> 

document.getElementById("new").innerHTML="Welcome to AIUB";
document.getElementById("new2").innerHTML="Welcome to Doomdays";


var para=document.getElementById("para");
para.style.color="red";
para.style.backgroundColor="blue";
para.style.fontWeight="bold";


function greet(){

alert("Hello World");

}


</script>
</body>


</html>