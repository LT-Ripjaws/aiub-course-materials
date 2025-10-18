<!DOCTYPE html>
<html>
<head>
  <title>Student Profile Checker</title>
</head>
<body>

  <h1>Student Profile Checker</h1>
  <p>Open the browser console to see the results.</p>

  <button onclick="showResult()">Show Student Result</button>

  <script>
    // 1. VARIABLES
    var studentName = "Rafi";
    var studentAge = 19;
    var isRegistered = true;

    var marksMath = 80;
    var marksEnglish = 75;
    var marksScience = 65;

    // 2. OPERATORS
    var totalMarks = marksMath + marksEnglish + marksScience;
    var averageMarks = totalMarks / 3;

    // 3. IF / ELSE CONDITIONS
    var ageStatus = (studentAge >= 18) ? "Adult" : "Minor";
    var resultStatus = (averageMarks >= 70) ? "Passed" : "Failed";

    // 4. LOOP - Print marks
    console.log("📄 Student Profile");
    console.log("Name:", studentName);
    console.log("Age:", studentAge);
    console.log("Status:", ageStatus);
    console.log("Total Marks:", totalMarks);
    console.log("Average Marks:", averageMarks.toFixed(2));
    console.log("Result:", resultStatus);

    console.log("\n📚 Subject Marks:");
    var subjects = ["Math", "English", "Science"];
    var marks = [marksMath, marksEnglish, marksScience];

    for (var i = 0; i < subjects.length; i++) {
      console.log(subjects[i] + ": " + marks[i]);
    }

    // 5. FUNCTION - Show Summary
    function showSummary() {
      console.log("\n🔍 Summary");
      console.log("Student: " + studentName);
      console.log("Age: " + studentAge + " (" + ageStatus + ")");
      console.log("Result: " + resultStatus + " with average " + averageMarks.toFixed(2));
    }

    showSummary();

    // 6. EVENT FUNCTION - Show Alert on Button Click
    function showResult() {
      if (resultStatus === "Passed") {
        alert("Average: " + averageMarks.toFixed(2) + "\nCongratulations, you passed!");
      } else {
        alert("Average: " + averageMarks.toFixed(2) + "\nSorry, you failed.");
      }
    }
  </script>

</body>
</html>
