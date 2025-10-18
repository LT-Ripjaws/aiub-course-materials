<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $user = $_POST["username"];
    $pass = $_POST["password"];
    $email = $_POST["email"];

    // Normally: Save into DB
    $success = "Registration successful! Now you can login.";
}
?>
<!DOCTYPE html>
<html>
<head>
  <title>Registration Page</title>
  <link rel="stylesheet" href="../css/style.css">
</head>
<body>
  <div class="container">
    <h2>Register</h2>
    <form method="post">
      <input type="text" name="username" placeholder="Username"><br>
      <input type="password" name="password" placeholder="Password"><br>
      <input type="email" name="email" placeholder="Email"><br>
      <input type="submit" value="Register">
    </form>
    <p class="success"><?php if(isset($success)) echo $success; ?></p>
  </div>
</body>
</html>
