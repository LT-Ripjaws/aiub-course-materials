<!DOCTYPE html>
<html>
<head>
  <title>DOM Without Functions</title>
</head>
<body>

  <h2 id="mainTitle">Original Heading</h2>

  <div id="container">
    <p id="originalPara">This is the original paragraph.</p>
  </div>

  <script>
    // 1. CREATE a new paragraph
    var newParagraph = document.createElement("p");
    newParagraph.innerHTML = "I am a newly created paragraph!";

     //2. APPEND it to the container
    var container = document.getElementById("container");
    container.appendChild(newParagraph); 

    // 3. REMOVE the original paragraph
    var oldParagraph = document.getElementById("originalPara");
    container.removeChild(oldParagraph);

    // 4. CREATE a new heading and REPLACE the old one
    var newHeading = document.createElement("h1");
    newHeading.innerHTML = "This heading replaced the old one";

    var oldHeading = document.getElementById("mainTitle");
    document.body.replaceChild(newHeading, oldHeading);

    // 5. OPTIONAL: use document.write (only if you want to overwrite)
     document.write("<h3>This replaced the whole page!</h3>"); */
  </script>

</body>
</html>
