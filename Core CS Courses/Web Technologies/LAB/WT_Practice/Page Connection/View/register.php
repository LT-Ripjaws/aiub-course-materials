<!DOCTYPE html>
<html>
<head>
  <title>Registration Page</title>
  <link rel="stylesheet" href="../css/style.css">
</head>
<body>
  <div class="container">
    <h2>Register</h2>

    <form action="register.php" method="POST">
      <input type="text" name="username" placeholder="Username"><br>
      <input type="password" name="password" placeholder="Password"><br>
      <input type="email" name="email" placeholder="Email"><br>
      <input type="submit" name="register" value="Register">

<a href="login.php"> Go Back to Login </a>

    </form>
<?php
if ($_SERVER ["REQUEST_METHOD"] == "POST")

  {
$name=$_POST["username"];
$pass=$_POST["password"];
$email=$_POST["email"];


if(empty($name) || empty($pass) || empty($email))

  {
  echo "Form cant be empty";
  }

else
{

  echo "Res complete";
  echo "Your name: ". $name . "<br>";
  echo "Your Pass: ". $pass . "<br>";
  echo "Your email: " .$email;
}
  }

?>

  </div>
</body>
</html>
