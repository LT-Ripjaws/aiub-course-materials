<!DOCTYPE html>
<html>
<head>
  <title>Color Switcher</title>
  <style>
    body {
      font-family: Arial, sans-serif;
      text-align: center;
      transition: background-color 0.4s, color 0.4s;
      padding: 50px;
    }

    #switchBtn {
      padding: 10px 20px;
      font-size: 16px;
      cursor: pointer;
    }

    h1 {
      margin-bottom: 40px;
    }
  </style>
</head>
<body>

  <h1 id="pageTitle">Light Mode</h1>
  <button id="switchBtn" onclick="toggleMode()">Switch Mode</button>

  <script>
    // Function to toggle light/dark mode
    function toggleMode() {
      var body = document.body;
      var title = document.getElementById("pageTitle");
      var button = document.getElementById("switchBtn");

      if (body.style.backgroundColor === "black") {
        // Switch to light mode
        body.style.backgroundColor = "white";
        body.style.color = "black";
        title.innerHTML = "Light Mode";
        button.innerHTML = "Switch to Dark Mode";
      } else {
        // Switch to dark mode
        body.style.backgroundColor = "black";
        body.style.color = "white";
        title.innerHTML = "Dark Mode";
        button.innerHTML = "Switch to Light Mode";
      }
    }
  </script>

</body>
</html>
