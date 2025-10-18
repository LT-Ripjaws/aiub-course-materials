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
      // Get values from form
      var name = document.getElementById("name").value;
      var id = document.getElementById("studentId").value;
      var age = document.getElementById("age").value;
      var department = document.getElementById("department").value;

      // Simple validation
      if (name === "" || id === "" || age === "" || department === "") {
        alert(" Please fill in all fields.");
        return false;
      }

    
}


      // Success message
      alert("✅ Registration Complete!\n\n" +
            "Name: " + name + "\n" +
            "ID: " + id + "\n" +
            "Age: " + age + "\n" +
            "Department: " + department);

      return false; // Prevent actual form submission (no page reload)
    }
  </script>

</body>
</html>
