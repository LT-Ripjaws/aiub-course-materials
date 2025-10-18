<?php
session_start();

// If already logged in, go directly to dashboard
if (isset($_SESSION["username"])) {
    header("Location: dashboard.php");
    exit();
}

// Process login
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $user = $_POST["username"];
    $pass = $_POST["password"];
    $remember = isset($_POST["remember"]);

    // Fake login check (normally check from DB)
    if ($user == "admin" && $pass == "1234") {
        $_SESSION["username"] = $user; // store in session

        // If user checked "remember me" → save in cookie
        if ($remember) {
            setcookie("username", $user, time() + (86400*30), "/"); // 30 days
        }

        header("Location: dashboard.php");
        exit();
    } else {
        $error = "Invalid username or password!";
    }
}
?>
<!DOCTYPE html>
<html>
<head>
  <title>Login Page</title>
  <link rel="stylesheet" href="../css/style.css">
</head>
<body>
  <div class="container">
    <h2>Login</h2>
    <form method="post">
      <input type="text" name="username" placeholder="Username"
             value="<?php echo isset($_COOKIE['username']) ? $_COOKIE['username'] : ''; ?>"><br>
      <input type="password" name="password" placeholder="Password"><br>
      <label><input type="checkbox" name="remember"> Remember Me</label><br>
      <input type="submit" value="Login">
    </form>
    <a href="register.php">New User? Register here</a>
    <p class="error"><?php if(isset($error)) echo $error; ?></p>
  </div>
</body>
</html>
