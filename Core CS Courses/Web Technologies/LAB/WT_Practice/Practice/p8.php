<!DOCTYPE html>
<html>
<head>
  <title>Color Switcher</title>
<h1 id="title">Hello</h1>
<p id="para">I am a student.</p>

<button onclick="greet()">Click Me</button>


<script> 
//var heading = document.getElementById("title");
document.getElementById("title").innerHTML = "Welcome to AIUB!";

var para = document.getElementById("para");
para.style.color = "red";
para.style.fontWeight = "bold";
 


 function greet() {
    alert("Hello! You clicked the button.");
  }
</script>
</head>
</html>