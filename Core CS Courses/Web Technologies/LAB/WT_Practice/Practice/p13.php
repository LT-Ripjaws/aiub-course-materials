<!DOCTYPE html>
<html>

<head> <title>  This is Form </title> </head>

<body>
<h1>
This is registration from with validation
</h1>

<form onsubmit= "return handelsubmit()" >

<label>
    Name:
</label>
<input type="text" id="name" /> <br>

<label>
    Age:
</label>
<input type="number" id="age" /> <br>

<label>
    Student ID:
</label>
<input type="text" id="Sid" /> <br>

<label> Department: </label>
<select id="dept">
<option value="">--Select Department -- </option>
<option value="CSE"> CSE </option>
<option value="EEE"> EEE </option>
<option value="IPE"> IPE </option>
<option value="BBA"> BBA </option>

</select>
<br>

<button type="submit"> Submit </button>

</form>



<script>
function handelsubmit()
{

var name = document.getElementById("name").value;
var age = document.getElementById("age").value;
var sid = document.getElementById("Sid").value;
var dept = document.getElementById("dept").value;


if( name=="" || age==""|| sid==""|| dept=="")
    {alert("Fill the form")
    return false
    }
  
alert("Registration Complete! \n" +

"Name:"+ name + "\n"+
"Age: "+ age +  "\n"+
"Sid: "+ sid + "\n" +
"Dept"+ dept
);

return false;
}


</script>



</body>
</html>