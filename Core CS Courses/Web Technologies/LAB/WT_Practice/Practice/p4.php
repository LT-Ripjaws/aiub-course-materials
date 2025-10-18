<!DOCTYPE html>
<html>
<head>
  <title>JavaScript Basic Concepts</title>
</head>
<body>

  <h1>Welcome to JavaScript Practice</h1>
  <p>Open your browser console to see the results. (Right-click → Inspect → Console)</p>

  <script>

    //  1. VARIABLES

    console.log(" VARIABLES");
    var name = "Hamim";
    var age = 25;
    var isStudent = true;
    console.log("Name:", name);
    console.log("Age:", age);
    console.log("Is Student?", isStudent);

    // 2. DATA TYPES

    console.log("\n DATA TYPES");
    var x; // undefined
    var y = null;
    var num = 3.14;
    var str = "Hello World";
    var flag = false;
    var obj = { course: "JavaScript", level: "Beginner" };
    console.log(typeof x);  // undefined
    console.log(typeof y);  // object (special case in JS)
    console.log(typeof num); // number
    console.log(typeof str); // string
    console.log(typeof flag); // boolean
    console.log(typeof obj);  // object

   

    //  4. OPERATORS

    console.log("\n OPERATORS");
    var a = 10;
    var b = 3;
    console.log("Addition:", a + b);
    console.log("Subtraction:", a - b);
    console.log("Multiplication:", a * b);
    console.log("Division:", a / b);
    console.log("Remainder:", a % b);


   //  5.IF / ELSE


     console.log("\n IF / ELSE");
    if (age >= 18) {
      console.log(name + " is an adult.");
    } else {
      console.log(name + " is a minor.");
    }

    //  6. LOOPS

    console.log("\n LOOPS");
    for (var i = 1; i <= 10; i++) {
      console.log("Loop Count: " + i);
    }

    //  7. FUNCTIONS

    console.log("\n FUNCTIONS");

    function greetUser(userName) {
      console.log("Hello, " + userName + "!");
    }

    greetUser("Hamim");
    //greetUser("Arifeen");

    // We'll add the button below HTML and attach event here

    function showMessage() {
      alert("You clicked the button!");
      console.log("Button was clicked.");
    }
  </script>

  <br><br>

  <button onclick="showMessage()">Click Me</button>

</body>
</html>
