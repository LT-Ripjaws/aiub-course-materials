<!DOCTYPE html>
<html>
<head>
  <title>Login Page</title>
  <link rel="stylesheet" href="../css/style.css">
</head>
<body>
  <div class="container">
    <h2>Login</h2>

 <form action="" method="POST">
  <input type="text" name="username" placeholder="Username"> 
  <input type="password" name="password" placeholder="Password">
  <button type="submit"> Submit </button>
  <a href="register.php"> Do you want to do the Registration </a>

<?php



if($_SERVER ["REQUEST_METHOD"] =="POST")
{
$name= $_POST["username"];
$pass = $_POST ["password"];


if($name=="admin" && $pass=="1234")
{
echo "Welcome to Admin";

}

else
{

echo"Invalid";
}
}


?>


  

</form>
 </div>




</body>
</html>
