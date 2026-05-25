/* A TypeScript interface is a compile-time construct that defines the shape (structure) of an object. 
It specifies what properties and methods an object must have and their types — without providing implementation.
Think of an interface as a contract: if something claims to follow that interface, it must match the defined structure.
TypeScript uses interfaces only for type checking, not at runtime. */

interface Person {
  id: number;
  name: string;
  isActive: boolean;
}

// Now any object typed as User must follow that structure:

const u: Person = {
  id: 1,
  name: "Alice",
  isActive: true
};

// If you miss a property or use the wrong type, TypeScript throws an error.

//Optional Properties:
// Use ? for fields that may or may not exist.

interface Person1 {
  id: number;
  name: string;
  age?: number;
}

// Valid:

const u1: Person1 = { id: 1, name: "Bob" };
const u2: Person1 = { id: 2, name: "Bob", age: 30 };

// Readonly Properties
// Cannot be changed after assignment.

interface Config {
  readonly apiKey: string;
}


// Function Interfaces
// Interfaces can describe function signatures.

interface AddFn {
  (a: number, b: number): number;
}

const adds: AddFn = (x, y) => x + y;



//Method Definitions
interface Logger {
  log(message: string): void;
}


// Extending Interfaces (Inheritance)
// Interfaces can extend other interfaces.

interface Person {
  name: string;
}

interface Employee extends Person {
  employeeId: number;
}


// Interfaces for Classes
// Classes can implement interfaces.

interface Animal {
  makeSound(): void;
}

class Dog implements Animal {
  makeSound() {
    console.log("Woof");
  }
}
// The class must satisfy the interface contract.


/*
Interface vs Type Alias (Important Distinction)
Both can describe object shapes, but:

Interfaces:
Designed for object contracts
Can be extended and merged
Preferred for OOP-style design

Type aliases:
More flexible (unions, tuples, primitives)
Cannot be reopened once declared
type ID = number | string;
Interfaces cannot do unions like this.

Interface Declaration Merging (Unique Feature):
Multiple interface declarations with same name are merged automatically.

interface User {
  name: string;
}

interface User {
  age: number;
}
  
// becomes:
interface User {
  name: string;
  age: number;
}
*/