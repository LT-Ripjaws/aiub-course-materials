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
let scores2: (string | number)[] = ['Programming', 5, 'Software Design', 4]; // this is a union type
console.log(scores2)

// TUPLES work like an array with some additional considerations: the number of elements and their types must be known at compile time.
// plus the order must be same
let user: [number, string, boolean] = [1, 'Chinmoy', true]
console.log(user[0]); // 1
console.log(user[1]); // Chinmoy
console.log(user[2]); // true

type TUser = [number, string]

const newUser1: TUser = [1, 'Chinmoy']





// Enums: An enum is a group of named constant values. Each value has a name and a value.
enum Color {
    Red = 1,
    Green = 2,
    Blue = 3
}
let color = Color.Red
console.log(color)

enum Month {
    Jan,
    Feb,
    Mar,
    Apr,
    May,
    Jun,
    Jul,
    Aug,
    Sep,
    Oct,
    Nov,
    Dec
};

function isItSummer(month: Month) {
  let isSummer: boolean;
  switch (month) {
    case Month.Jun:
    case Month.Jul:
    case Month.Aug:
      isSummer = true;
      break;
    default:
      isSummer = false;
      break;
  }
  return isSummer;
}

console.log(isItSummer(Month.Jun)); // true

/*
You should use an enum when you:

Have a small set of closely related fixed values.
And these values are known at compile time.
For example, you can use an enum for the approval status:

enum ApprovalStatus {
    draft,
    submitted,
    approved,
    rejected
};
Code language: TypeScript (typescript)
Then, you can use the ApprovalStatus enum like this:

const request =  {
    id: 1,
    status: ApprovalStatus.approved,
    description: 'Please approve this request'
};

if(request.status === ApprovalStatus.approved) {
    // send an email
    console.log('Send email to the Applicant...');
}
*/


