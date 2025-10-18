<?php
include "config.php"; // connect DB

$success = $error = "";

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $username = $_POST["username"];
    $password = $_POST["password"];
    $email = $_POST["email"];

    // simple validation
    if (empty($username) || empty($password) || empty($email)) {
        $error = "All fields are required!";
    } else {
        // hash password (important for security!)
        $hashedPassword = password_hash($password, PASSWORD_DEFAULT);

        // insert into database
        $sql = "INSERT INTO users (username, password, email) VALUES ('$username', '$hashedPassword', '$email')";
        if ($conn->query($sql) === TRUE) {
            $success = "Registration successful! You can now login.";
        } else {
            $error = "Error: " . $conn->error;
        }
    }
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>User Registration</title>
</head>
<body>
    <h2>Register</h2>
    <form method="post" action="">
        Username: <input type="text" name="username"><br><br>
        Password: <input type="password" name="password"><br><br>
        Email: <input type="email" name="email"><br><br>
        <input type="submit" value="Register">
    </form>

    <p style="color:green;"><?php echo $success; ?></p>
    <p style="color:red;"><?php echo $error; ?></p>
</body>
</html>
