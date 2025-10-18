<?php
session_start();
session_unset();
session_destroy();
?>
<!DOCTYPE html>
<html>
<head>
  <title>Logout</title>
  <link rel="stylesheet" href="../css/style.css">
</head>
<body>
  <div class="container">
    <h2>You are logged out.</h2>
    <a href="login.php"><button>Login Again</button></a>
  </div>
</body>
</html>
