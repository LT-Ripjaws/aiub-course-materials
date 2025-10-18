<!DOCTYPE html>
<html>
<head>
  <title>Form Handler</title>
  <style>
    body {
      font-family: Arial, sans-serif;
      padding: 30px;
      background-color: #f0f8ff;
    }

    h2 {
      text-align: center;
      color: #003366;
    }

    form {
      background-color: #ffffff;
      padding: 20px;
      border-radius: 10px;
      width: 300px;
      margin: 0 auto;
      box-shadow: 0 0 10px rgba(0,0,0,0.1);
    }

    input, select, button {
      width: 100%;
      padding: 8px;
      margin-top: 10px;
      border-radius: 5px;
      border: 1px solid #ccc;
    }

    button {
      background-color: #003366;
      color: white;
      cursor: pointer;
    }

    button:hover {
      background-color: #0055aa;
    }
  </style>
</head>
<body>

  <h2>Registration Form</h2>

  <form onsubmit="return handleSubmit()">
    <label>Name:</label>
    <input type="text" id="name" />

    <label>ID:</label>
    <input type="text" id="studentId" />

    <label>Age:</label>
    <input type="number" id="age" />

    <label>Mobile Number:</label>
    <input type="text" id="mobile" />

    <label>Email:</label>
    <input type="email" id="email" />

    <label>Password:</label>
    <input type="password" id="password" />

    <label>Department:</label>
    <select id="department">
      <option value="">-- Select Department --</option>
      <option value="CSE">CSE</option>
      <option value="EEE">EEE</option>
      <option value="BBA">BBA</option>
    </select>

    <button type="submit">Submit</button>
  </form>

  <script>
    function handleSubmit() {
      var name = document.getElementById("name").value;
      var id = document.getElementById("studentId").value;
      var age = document.getElementById("age").value;
      var mobile = document.getElementById("mobile").value;
      var email = document.getElementById("email").value;
      var password = document.getElementById("password").value;
      var department = document.getElementById("department").value;

      // Empty field check
      if (
        name === "" || id === "" || age === "" ||
        mobile === "" || email === "" || password === "" || department === ""
      ) {
        alert("Please fill in all fields.");
        return false;
      }

      // ID check (5-digit)
      if (id.length !== 5 || isNaN(id)) {
        alert("ID must be exactly 5 digits.");
        return false;
      }

      // Age check (<25)
      if (parseInt(age) >= 25) {
        alert(" Age must be less than 25.");
        return false;
      }

      // Mobile number validation (11-digit number only)
      if (!/^\d{11}$/.test(mobile)) {
        alert(" Mobile number must be exactly 11 digits.");
        return false;
      }

      // Password validation
      const passwordPattern = /^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)(?=.*[\W_]).{8,}$/;
      if (!passwordPattern.test(password)) {
        alert("Password must be at least 8 characters and include:\n- 1 lowercase letter\n- 1 uppercase letter\n- 1 number\n- 1 special character");
        return false;
      }

      // Success message
      alert("Registration Complete!\n\n" +
            "Name: " + name + "\n" +
            "ID: " + id + "\n" +
            "Age: " + age + "\n" +
            "Mobile: " + mobile + "\n" +
            "Email: " + email + "\n" +
            "Department: " + department);

      return false; // Prevent actual form submission
    }
  </script>

</body>
</html>
