/* 
TypeScript inherits the built-in types from JavaScript. TypeScript types are categorized into:

Primitive types - string, number, boolean, null, undefined, symbol
Object types - functions, arrays, classes and objects 
*/

// Number type:
let num1: number = 10;
let num2: number = 20;

let num3 = 30;

let big: bigint = 9007199254740991n;

// String type:
let str1: string = "Hello, World!";
let str2 = "Woowoowow";

let str3 = "This is a string with a number: " + num1;

console.log(typeof(str3))

// Boolean type:
let bool1: boolean = true;
let isLoggedIn = false;

const hasError: boolean = false;
const completed: boolean = true;

// AND operator
let result = completed && hasError; 
console.log(result); // false

// OR operator
result = completed || hasError; 
console.log(result); // true
// -----------------------------------


// Object Type:
let employee: {
    id: number,
    name: string,
    age: number
}

employee = {
    id: 1,
    name: "Jane Doe Na",
    age: 30
}

console.log(employee.name);

// Array Type:
let skills = ['Problem Sovling','Software Design','Programming'];
console.log(skills.map(skill => skill.toLocaleUpperCase()));


let series = [1, 2, 3];
console.log(series.length); // 3

let doubleIt = series.map(e => e* 2);
console.log(doubleIt);


let scores = ['Programming', 5, 'Software Design', 4]; 
console.log(typeof(scores))

// same as:
let scores2: (string | number)[] = ['Programming', 5, 'Software Design', 4]; 
console.log(scores2)