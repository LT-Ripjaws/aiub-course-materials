// Like JavaScript, you use the function keyword to declare a function in TypeScript:

function add(num1: number, num2: number): number{
    return num1 + num2;
}

let sum = add(10, 20);

console.log(sum)

// The : number after the parentheses indicate the return type. The add() function returns a value of the number type in this case.
// We can use a void if the function does not return any value:

function echo(message: string): void {
    console.log(message.toUpperCase());
}
echo("bruh")


function signUpUser(name: string, email: string): void {
    let user: {} // we can do {}, object, or interface or {name: string, email: string}

    user = {
        name: name,
        email: email
    }

    console.log(user)
}
signUpUser("bruh", "bruh@bruh")



let users: object[] = []

const User1 = {
    name: "Legit",
    email: "veryLegit@techno.co",
    isActive: true
}

users.push(User1)
function createUser(name: string, email: string) {
    
    let newUser = {}

    newUser = {
        name: name,
        email: email,
        isActive: true
    }

    users.push(newUser)
}

createUser("Chinmoy", "chinmoy@gmail.com")

console.log(users)

// -----------------------------

// Type Aliases:
type User = {
    name: string,
    age: number,
    email?: string
}

let users2: User[] = []
function createUserAgain(user: User){
    users2.push(user)
}

createUserAgain({ name: "Legit", age: 25 })

console.log(users2)


type alphanumeric = string | number;

let input: alphanumeric;
input = 100; // valid
input = 'Hi'; // valid

// -------------------------------
// Function overloading allows you to define multiple signatures for a single function and provide one implementation that handles all defined signatures.
// Function overloading is useful when you want to provide different implementations for the same function based on the number or type of arguments passed to it.



let addN: (a: number, b: number) => number =
    function (x: number, y: number) {
        return x + y;
    };
// Here addN is the variable, 
// (a: number, b: number) => number is the function type.
// And the rest is the function assigned to the add variable.
// This is Function types


// Moreover there are optional parameters given with a question mark (?).
// default parameters for a function are like
function applyDiscount(price: number, discount = 0.05) {
    return price * (1 - discount);
}

console.log(applyDiscount(100))

// --------------------------------


// A rest parameter allows a function to accept zero or more arguments of the specified type.
/* 
Rest parameters with a single type
To declare a rest parameter, you prefix the parameter name with three dots (…) and use the array type as the type annotation:

function fn(...rest: type[]) {
   //...
}
Code language: JavaScript (javascript)
The following example shows how to use the rest parameter:

function getTotal(...numbers: number[]): number {
    let total = 0;
    numbers.forEach((num) => total += num);
    return total;
}
Code language: JavaScript (javascript)
In this example, the getTotal() calculates the total of numbers passed into it.

Since the numbers parameter is a rest parameter, you can pass one or more numbers to calculate the total:

console.log(getTotal()); // 0
console.log(getTotal(10, 20)); // 30
console.log(getTotal(10, 20, 30)); // 60
*/

// --------------------------------------


// Structural Typing:
interface Point2D {
  x: number;
  y: number;
}

let point3D = { x: 1, y: 2, z: 3 };

function logPoint(p: Point2D) {
  console.log(p.x, p.y);
}

logPoint(point3D); // This works because point3D has 'x' and 'y'
// Shape matters not the size.