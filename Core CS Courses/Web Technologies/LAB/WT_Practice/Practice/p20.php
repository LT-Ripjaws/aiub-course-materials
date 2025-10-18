<!DOCTYPE html>
<html>
<head>
    <title>Student Marks Entry</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 20px;
        }
        table {
            border-collapse: collapse;
            margin-top: 20px;
            width: 50%;
        }
        th, td {
            border: 1px solid #000;
            padding: 8px;
            text-align: center;
        }
        th {
            background-color: #ddd;
        }
        .error {
            color: red;
            margin-top: 5px;
        }
    </style>
</head>
<body>

<h2>Enter Student Details</h2>

<label for="studentName">Name:</label>
<input type="text" id="studentName">
<br><br>

<label for="studentMarks">Marks:</label>
<input type="number" id="studentMarks">
<br><br>

<button onclick="addStudent()">Submit</button>

<p id="errorMessage" class="error"></p>

<table id="studentsTable">
    <thead>
        <tr>
            <th>Name</th>
            <th>Marks</th>
        </tr>
    </thead>
    <tbody>
    </tbody>
</table>

<script>
function addStudent() {
    const nameInput = document.getElementById('studentName').value.trim();
    const marksInput = document.getElementById('studentMarks').value.trim();
    const errorMsg = document.getElementById('errorMessage');

    // Name validation: not empty, letters only
    const namePattern = /^[A-Za-z]+$/;
    if (!namePattern.test(nameInput)) {
        errorMsg.textContent = "Name must contain only letters with no spaces or special characters.";
        return;
    }

    // Marks validation: number between 0 and 100
    const marks = Number(marksInput);
    if (isNaN(marks) || marks < 0 || marks > 100) {
        errorMsg.textContent = "Marks must be a number between 0 and 100.";
        return;
    }

    errorMsg.textContent = ""; // Clear error message

    // Add new row to table
    const tableBody = document.querySelector('#studentsTable tbody');
    const newRow = tableBody.insertRow();
    const nameCell = newRow.insertCell(0);
    const marksCell = newRow.insertCell(1);

    nameCell.textContent = nameInput;
    marksCell.textContent = marks;

    // Set row color based on marks
    if (marks > 50) {
        newRow.style.backgroundColor = 'lightgreen';
    } else {
        newRow.style.backgroundColor = 'lightcoral';
    }

    // Clear inputs
    document.getElementById('studentName').value = '';
    document.getElementById('studentMarks').value = '';
}
</script>

</body>
</html>
