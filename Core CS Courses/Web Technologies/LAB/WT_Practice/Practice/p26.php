<!DOCTYPE html>
<html>
<head>
    <title>GET vs POST Example</title>
</head>
<body>
    <h2>Form Handling Example</h2>

    <!-- ------------------ POST FORM ------------------ -->
    <h3>POST Form (hidden data)</h3>
    <form method="post" action="">
        Name: <input type="text" name="post_name">
        <input type="submit" value="Submit with POST">
    </form>

    <!-- ------------------ GET FORM ------------------ -->
    <h3>GET Form (data visible in URL)</h3>
    <form method="get" action="">
        Name: <input type="text" name="get_name">
        <input type="submit" value="Submit with GET">
    </form>

    <hr>

<?php
// ------------------ HANDLE POST DATA ------------------
if ($_SERVER["REQUEST_METHOD"] == "POST" && !empty($_POST["post_name"])) {
    $postName = $_POST["post_name"];
    echo "<p><b>POST Data Received:</b> " . htmlspecialchars($postName) . "</p>";
}

// ------------------ HANDLE GET DATA ------------------
if ($_SERVER["REQUEST_METHOD"] == "GET" && !empty($_GET["get_name"])) {
    $getName = $_GET["get_name"];
    echo "<p><b>GET Data Received:</b> " . htmlspecialchars($getName) . "</p>";
}
?>
</body>
</html>
