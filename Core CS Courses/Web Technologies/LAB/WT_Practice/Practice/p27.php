<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <title>jQuery Demo</title>
  <!-- Load jQuery from CDN -->
  <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
  <style>
    body { font-family: Arial, sans-serif; margin: 20px; }
    button { margin: 5px; padding: 8px 12px; }
    #box { width: 150px; height: 150px; background: lightblue; margin-top: 10px; }
    #result { margin-top: 15px; padding: 10px; border: 1px solid #ccc; }
  </style>
</head>
<body>
  <h2>jQuery Demo Page</h2>

  <!-- Example 1: Change text -->
  <h3>1. Change Text</h3>
  <p id="text">Hello World!</p>
  <button id="changeTextBtn">Change Text</button>

  <!-- Example 2: Hide/Show -->
  <h3>2. Hide and Show</h3>
  <p id="para">This paragraph can hide and show.</p>
  <button id="hideBtn">Hide</button>
  <button id="showBtn">Show</button>

  <!-- Example 3: Animation -->
  <h3>3. Animation</h3>
  <button id="animateBtn">Animate Box</button>
  <div id="box"></div>

  <!-- Example 4: AJAX -->
  <h3>4. AJAX Request</h3>
  <button id="ajaxBtn">Load Data</button>
  <div id="result">Click the button to load data...</div>

  <script>
    // Example 1: Change text
    $("#changeTextBtn").click(function() {
      $("#text").text("Hello from jQuery!");
    });

    // Example 2: Hide/Show
    $("#hideBtn").click(function() {
      $("#para").hide();
    });
    $("#showBtn").click(function() {
      $("#para").show();
    });

    // Example 3: Animate
    $("#animateBtn").click(function() {
      $("#box").animate({ width: "300px", height: "300px" }, 1000)
               .animate({ width: "150px", height: "150px" }, 1000);
    });

    // Example 4: AJAX (loading text file)
    $("#ajaxBtn").click(function() {
      $.get("data.txt", function(response) {
        $("#result").html(response);
      });
    });
  </script>
</body>
</html>
