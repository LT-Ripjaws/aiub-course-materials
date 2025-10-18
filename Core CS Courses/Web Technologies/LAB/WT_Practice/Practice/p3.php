<!DOCTYPE html>
<html>
<head>
  <title>AIUB Management System</title>

  <style>
    body {
      font-family: Arial, sans-serif;
      background-color: #f0f8ff;
    }

    h1, h2 {
      color: #003366;
    }

    table {
      background-color: #ffffff;
      border: 1px solid #ccc;
      padding: 15px;
      margin-top: 20px;
    }

    input[type="text"],
    input[type="email"],
    input[type="password"],
    input[type="file"] {
      padding: 5px;
      width: 95%;
    }

    input[type="submit"]:hover,
    input[type="reset"]:hover {
      background-color: #0055aa;
    }
  </style>
</head>

<body>

  <center>
    <h1>AIUB Management System</h1>
    <h2>We Create Future</h2>
  </center>

  <h1 align="left">Registration Form</h1>

  <!-- ✅ Start of Form -->
  <form>
    <table>
      <tr>
        <td>First Name:</td>
        <td><input type="text" name="fname"></td>
      </tr>
      <tr>
        <td>Last Name:</td>
        <td><input type="text" name="lname"></td>
      </tr>
      <tr>
        <td>Age:</td>
        <td><input type="text" name="age"></td>
      </tr>
      <tr>
        <td>Designation:</td>
        <td>
          <input type="radio" name="designation">Junior Position
          <input type="radio" name="designation">Senior Position
          <input type="radio" name="designation">Project Lead
        </td>
      </tr>
      <tr>
        <td>Preferred Language:</td>
        <td>
          <input type="checkbox" name="lang">JAVA
          <input type="checkbox" name="lang">PHP
          <input type="checkbox" name="lang">C++
        </td>
      </tr>
      <tr>
        <td>E-mail:</td>
        <td><input type="email" name="email"></td>
      </tr>
      <tr>
        <td>Enter a Password:</td>
        <td><input type="password" name="password"></td>
      </tr>
      <tr>
        <td>Please choose a file:</td>
        <td><input type="file" name="file"></td>
      </tr>
      <tr>
        <td colspan="2" align="center">
          <input type="submit" name="submit">
          <input type="reset" name="reset">
        </td>
      </tr>
    </table>
  </form>
  <!-- ✅ End of Form -->

  <!-- ✅ End of JavaScript -->

</body>
</html>
