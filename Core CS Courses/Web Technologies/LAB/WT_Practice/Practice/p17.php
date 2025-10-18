<!DOCTYPE html>
<html>
<head>
    <title>Restaurant Order Management</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 20px;
            background-color: #f5f5f5;
        }
        .container {
            background-color: white;
            padding: 20px;
            border-radius: 8px;
            box-shadow: 0 2px 4px rgba(0,0,0,0.1);
            max-width: 800px;
            margin: 0 auto;
        }
        h2 {
            color: #333;
            text-align: center;
        }
        table {
            border-collapse: collapse;
            margin-top: 20px;
            width: 100%;
        }
        th, td {
            border: 1px solid #ddd;
            padding: 12px;
            text-align: left;
        }
        th {
            background-color: #f2f2f2;
            font-weight: bold;
        }
        tr:nth-child(even) {
            background-color: #f9f9f9;
        }
        .error {
            color: red;
            margin-top: 5px;
        }
        .form-group {
            margin-bottom: 15px;
        }
        label {
            display: block;
            margin-bottom: 5px;
            font-weight: bold;
        }
        input, select {
            width: 100%;
            padding: 8px;
            border: 1px solid #ddd;
            border-radius: 4px;
            box-sizing: border-box;
        }
        button {
            background-color: #4CAF50;
            color: white;
            padding: 10px 15px;
            border: none;
            border-radius: 4px;
            cursor: pointer;
            font-size: 16px;
        }
        button:hover {
            background-color: #45a049;
        }
        .total-row {
            font-weight: bold;
            background-color: #e7f3fe !important;
        }
        .delete-btn {
            background-color: #f44336;
            color: white;
            padding: 5px 10px;
            border: none;
            border-radius: 4px;
            cursor: pointer;
        }
    </style>
</head>
<body>
<div class="container">
    <h2>Restaurant Order Management</h2>

    <div class="form-group">
        <label for="itemName">Item Name:</label>
        <input type="text" id="itemName" placeholder="Enter item name">
    </div>

    <div class="form-group">
        <label for="itemPrice">Price ($):</label>
        <input type="number" id="itemPrice" min="0" step="0.01" placeholder="Enter price">
    </div>

    <div class="form-group">
        <label for="itemQuantity">Quantity:</label>
        <input type="number" id="itemQuantity" min="1" value="1" placeholder="Enter quantity">
    </div>

    <div class="form-group">
        <label for="itemCategory">Category:</label>
        <select id="itemCategory">
            <option value="Appetizer">Appetizer</option>
            <option value="Main Course">Main Course</option>
            <option value="Dessert">Dessert</option>
            <option value="Beverage">Beverage</option>
        </select>
    </div>

    <button onclick="addItem()">Add to Order</button>
    <button onclick="calculateTotal()" style="background-color: #2196F3; margin-left: 10px;">Calculate Total</button>

    <p id="errorMessage" class="error"></p>

    <table id="orderTable">
        <thead>
            <tr>
                <th>Item Name</th>
                <th>Category</th>
                <th>Price</th>
                <th>Quantity</th>
                <th>Subtotal</th>
                <th>Action</th>
            </tr>
        </thead>
        <tbody>
        </tbody>
        <tfoot>
            <tr class="total-row">
                <td colspan="4" style="text-align: right;">Total:</td>
                <td id="totalAmount">$0.00</td>
                <td></td>
            </tr>
        </tfoot>
    </table>
</div>

<script>
function addItem() {
    const nameInput = document.getElementById('itemName').value.trim();
    const priceInput = document.getElementById('itemPrice').value;
    const quantityInput = document.getElementById('itemQuantity').value;
    const categoryInput = document.getElementById('itemCategory').value;
    const errorMsg = document.getElementById('errorMessage');

    // Validation
    if (nameInput === '') {
        errorMsg.textContent = "Please enter an item name.";
        return;
    }

    const price = parseFloat(priceInput);
    if (isNaN(price) || price <= 0) {
        errorMsg.textContent = "Please enter a valid price greater than 0.";
        return;
    }

    const quantity = parseInt(quantityInput);
    if (isNaN(quantity) || quantity < 1) {
        errorMsg.textContent = "Please enter a valid quantity (at least 1).";
        return;
    }

    errorMsg.textContent = ""; // Clear error message

    // Add new row to table
    const tableBody = document.querySelector('#orderTable tbody');
    const newRow = tableBody.insertRow();
    
    const nameCell = newRow.insertCell(0);
    const categoryCell = newRow.insertCell(1);
    const priceCell = newRow.insertCell(2);
    const quantityCell = newRow.insertCell(3);
    const subtotalCell = newRow.insertCell(4);
    const actionCell = newRow.insertCell(5);

    const subtotal = price * quantity;

    nameCell.textContent = nameInput;
    categoryCell.textContent = categoryInput;
    priceCell.textContent = '$' + price.toFixed(2);
    quantityCell.textContent = quantity;
    subtotalCell.textContent = '$' + subtotal.toFixed(2);
    
    // Add delete button
    const deleteBtn = document.createElement('button');
    deleteBtn.textContent = 'Delete';
    deleteBtn.className = 'delete-btn';
    deleteBtn.onclick = function() {
        tableBody.removeChild(newRow);
        calculateTotal();
    };
    actionCell.appendChild(deleteBtn);

    // Clear inputs
    document.getElementById('itemName').value = '';
    document.getElementById('itemPrice').value = '';
    document.getElementById('itemQuantity').value = '1';
    
    // Automatically calculate total
    calculateTotal();
}

function calculateTotal() {
    const tableBody = document.querySelector('#orderTable tbody');
    const rows = tableBody.rows;
    let total = 0;

    for (let i = 0; i < rows.length; i++) {
        const subtotalText = rows[i].cells[4].textContent;
        const subtotal = parseFloat(subtotalText.substring(1)); // Remove $ sign
        total += subtotal;
    }

    document.getElementById('totalAmount').textContent = '$' + total.toFixed(2);
}
</script>

</body>
</html>