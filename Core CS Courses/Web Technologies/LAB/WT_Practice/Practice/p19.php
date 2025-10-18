<!DOCTYPE html>
<html>
<head>
    <title>PHP Form Validation Example</title>
</head>
<body>
    <h2>Form Validation in PHP</h2>

<?php
// -------------------- PHP VALIDATION LOGIC --------------------

// Step 1: Define variables (start empty)
$name = $age = $email = "";
$nameErr = $ageErr = $emailErr = "";

// Step 2: Run validation only when form is submitted
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    
    // --- Validate Name ---
    if (empty($_POST["name"])) {
        $nameErr = "Name is required"; // error if empty
    } else {
        $name = test_input($_POST["name"]); // clean input
        // check if only letters and spaces
        if (!preg_match("/^[a-zA-Z-' ]*$/",$name)) {
            $nameErr = "Only letters and spaces allowed";
        }
    }

    // --- Validate Age ---
    if (empty($_POST["age"])) {
        $ageErr = "Age is required";
    } else {
        $age = test_input($_POST["age"]); // clean input
        // check if number and in valid range
        if (!is_numeric($age) || $age < 1 || $age > 120) {
            $ageErr = "Enter a valid age (1–120)";
        }
    }

    // --- Validate Email ---
    if (empty($_POST["email"])) {
        $emailErr = "Email is required";
    } else {
        $email = test_input($_POST["email"]); // clean input
        // check if valid email format
        if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
            $emailErr = "Invalid email format";
        }
    }
}

// Step 3: Function to clean input (security + neatness)
function test_input($data) {
    $data = trim($data);             // remove extra spaces
    $data = stripslashes($data);     // remove backslashes
    return $data;
}

?>

<!-- -------------------- HTML FORM -------------------- -->
<form method="post" action="">
    Name: <input type="text" name="name" value="<?php echo $name; ?>">
    <span style="color:red">* <?php echo $nameErr; ?></span>
    <br><br>

    Age: <input type="text" name="age" value="<?php echo $age; ?>">
    <span style="color:red">* <?php echo $ageErr; ?></span>
    <br><br>

    Email: <input type="text" name="email" value="<?php echo $email; ?>">
    <span style="color:red">* <?php echo $emailErr; ?></span>
    <br><br>

    <input type="submit" name="submit" value="Submit">
</form>

<?php
// -------------------- SHOW DATA IF VALID --------------------
if ($_SERVER["REQUEST_METHOD"] == "POST" && empty($nameErr) && empty($ageErr) && empty($emailErr)) {
    echo "<h3>Your Input:</h3>";
    echo "Name: $name <br>";
    echo "Age: $age <br>";
    echo "Email: $email <br>";
}




?>

</body>
</html>
