<?php
$host = "localhost";   // database server
$user = "root";        // database username
$pass = "";            // database password
$dbname = "user_system"; // database name

$conn = new mysqli($host, $user, $pass, $dbname);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}
?>
