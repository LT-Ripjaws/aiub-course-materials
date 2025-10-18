<!DOCTYPE html>
<html>
<head>
  <title>AIUB Management System</title>
  
</head>

<body>

  <center>
    <h1 style="color: brown;">AIUB Management System</h1>
    <h1>AIUB System</h1>
    <h2>We Create Future</h2>
  </center>

  <h1 align="left">Registration Form</h1>
  <p id="para" >This is the ID use </p>
  <p class="para1" >This is the ID use </p>

  <p style="color green;">Hello</p>


<style>

h1{
font-family: Arial, Helvetica, sans-serif;
color: blue;
font-size: 30px;

}
h2{

    font-size: 25px;
    color: green;
}
body{
background-color: #d4deebff;
font-family: 'Times New Roman', Times, serif;
}

table{
margin-top: 5px;
border: 2px solid black;
background-color: wheat;
padding: 10px;
margin-left: auto;
margin-right: auto;

}
input[type="text"],input[type="email"],input[type="password"]
{
padding: 5px;
width: 90%;

}

input[type="submit"],input[type="reset"]
{
padding: 10px;

}

#para {

    color:blue;
    font-family:Arial, Helvetica, sans-serif;
    font-size: large;
    
}

.para1 {

 color:red;
    font-family:Georgia, Times, 'Times New Roman', serif;
    font-size: large;


}

</style>



  <form>
    <table>
      <tr>
        <td>First Name:</td>
        <td><input type="text" name="fname"></td>
      </tr>
      <tr>
        <td>Last Name:</td>
        <td><input type="text" name="lname"></td>
      </tr>
      <tr>
        <td>Age:</td>
        <td><input type="text" name="age"></td>
      </tr>
      <tr>
        <td>Designation:</td>
        <td>
          <input type="radio" name="designation">Junior Position
          <input type="radio" name="designation">Senior Position
          <input type="radio" name="designation">Project Lead
        </td>
      </tr>
      <tr>
        <td>Preferred Language:</td>
        <td>
          <input type="checkbox" name="lang">JAVA
          <input type="checkbox" name="lang">PHP
          <input type="checkbox" name="lang">C++
        </td>
      </tr>
      <tr>
        <td>E-mail:</td>
        <td><input type="email" name="email"></td>
      </tr>
      <tr>
        <td>Enter a Password:</td>
        <td><input type="password" name="password"></td>
      </tr>
      <tr>
        <td>Please choose a file:</td>
        <td><input type="file" name="file"></td>
      </tr>
      <tr>
        <td colspan="2" align="center">
          <input type="submit" name="submit">
          <input type="reset" name="reset">
        </td>
      </tr>
    </table>
  </form>


</body>
</html>
