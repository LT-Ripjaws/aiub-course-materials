<?php
session_start();

// If not logged in, redirect to login
if (!isset($_SESSION["username"])) {
    header("Location: login.php");
    exit();
}
?>
<!DOCTYPE html>
<html>
<head>
  <title>Dashboard</title>
  <link rel="stylesheet" href="../css/style.css">
</head>
<body>
  <div class="container">
    <h2>Welcome, <?php echo $_SESSION["username"]; ?> 🎉</h2>

    <?php
    // If cookie exists, show welcome back message
    if (isset($_COOKIE["username"])) {
        echo "<p>Welcome back, " . $_COOKIE["username"] . " (from cookie)</p>";
    }
    ?>

    <p>This is your private dashboard. Only logged-in users can see this.</p>
    <a href="logout.php"><button>Logout</button></a>
  </div>
</body>
</html>
