<!DOCTYPE html>
<html>
<head>
  <title>Validation with innerHTML</title>
  <style>
    body {
      font-family: Arial;
      background-color: #f0f8ff;
      padding: 20px;
    }

    form {
      background: white;
      padding: 20px;
      max-width: 400px;
      margin: auto;
      border-radius: 8px;
      box-shadow: 0 0 10px rgba(0,0,0,0.1);
    }

    label {
      font-weight: bold;
    }

    input {
      width: 100%;
      padding: 8px;
      margin-top: 4px;
      margin-bottom: 8px;
      border: 1px solid #ccc;
      border-radius: 5px;
    }

    span {
      color: red;
      font-size: 14px;
    }

    button {
      background-color: #003366;
      color: white;
      padding: 10px;
      width: 100%;
      border: none;
      border-radius: 5px;
      cursor: pointer;
    }

    button:hover {
      background-color: #0055aa;
    }
  </style>
</head>
<body>

  <h2 style="text-align: center;">Simple Form with Validation</h2>

  <form onsubmit="return handleSubmit()">
    <label>First Name:</label><br>
    <input type="text" id="firstName"><br>
    <span id="nameError"></span><br>

    <label>Email:</label><br>
    <input type="text" id="email"><br>
    <span id="emailError"></span><br>

    <button type="submit">Submit</button>
  </form>

  <script>
    function handleSubmit() {
      // Clear old messages
   var valid=document.getElementById("nameError");
    valid.innerHTML = "";
    valid.innerHTML = "";

      var firstName = document.getElementById("firstName").value;
      var email = document.getElementById("email").value;
      var hasError = false;

      // First Name validation
      if (firstName.trim() === "") {
        document.getElementById("nameError").innerHTML = "First Name is required";
        hasError = true;
      }

      // Email validation (simple version)
      if (email.trim() === "") {
        document.getElementById("emailError").innerHTML = "Email is required";
        hasError = true;
      } else if (!email.includes("@") || !email.includes(".")) {
        document.getElementById("emailError").innerHTML = "Invalid email address";
        hasError = true;
      }

      //  hamim

      // Final result
      if (hasError) {
        return false; // prevent form submission
      }

      alert("Form submitted successfully!");
      return false;
    }
  </script>

</body>
</html>
