// Suppose we have two functions, one that takes an array of numbers and returns the sum of all numbers, and another that takes an array of strings and returns the concatenated string.
// later we may need to create another function, but the mechanism of all three functions would pretty much be same and we don't want to write the same code over and over again.
// We can use generics to solve this problem.
// Generics allow you to create a function that can work with different types of data without explicitly specifying the type of the data.
// Instead, you specify the type of the data when you call the function.

function getRandomElement<T>(items: T[]): T {
    let randomIndex = Math.floor(Math.random() * items.length);
    return items[randomIndex];
}

// Here we have used T as a generic type parameter. This means that the function getRandomElement can work with any type of data.
// We pass the type of the data as an argument when we call the function.
// For example, we can call getRandomElement with an array of numbers like this:

let numbers = [1, 2, 3, 4, 5];

let randomNumber = getRandomElement(numbers);

console.log(randomNumber);

// We can also call getRandomElement with an array of strings like this:
let strings = ['Hello', 'World', 'This', 'Is', 'A', 'String'];

let randomString = getRandomElement(strings);

console.log(randomString);

// TypeScript generics allow you to write reusable and generalized forms of functions, classes, and interfaces.
// Generics provide a powerful way to write code that can work with different types of data without explicitly specifying the type of the data.


// you may add constraints to the generic type parameter to restrict the types that can be used with the generic function.
// For example, we can restrict the type of the data to be a number like this:
function getRandomElementz<T extends number>(items: T[]): T {
    let randomIndex = Math.floor(Math.random() * items.length);
    return items[randomIndex];
}

// generics work with both classes and interfaces
interface Personz<T> {
    name: string;
    data: T;
}

const personz: Personz<number> = {
    name: "John",
    data: 10
};  

class Stack<T> {
    private elements: T[] = [];
    private size: number;

    constructor(size: number) {
        this.size = size;
    }
    isEmpty(): boolean {
        return this.elements.length === 0;
    }
    isFull(): boolean {
        return this.elements.length === this.size;
    }
    push(element: T): void {
        if (this.elements.length === this.size) {
            throw new Error('The stack is overflow!');
        }
        this.elements.push(element);

    }
    pop(): void {
        if (this.elements.length == 0) {
            throw new Error('The stack is empty!');
        }
         this.elements.pop();
    }
}

let numberz = new Stack<number>(5);
numberz.push(1);
numberz.push(5);

console.log(numberz); 

// we can use this same class for strings as well
let stringz = new Stack<string>(5);
stringz.push("Hello");
stringz.push("World");

console.log(stringz);