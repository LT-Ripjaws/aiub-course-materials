class GoodPerson {
    public name: string // for typescript we have to explicitly define the type and the variables in the class before the constructor
    private email: string // access modifiers private, public, protected are to make sure that the variable's accessibility is controlled
    readonly city: string = "Dhaka" // readonly means that the variable cannot be changed after initialization
    constructor(name: string = "defaultName", email: string = "default@gmail.com"){
        this.name = name
        this.email = email
    }

    LogDetails(): void {
        console.log(`Name: ${this.name}, Email: ${this.email}`)
    }

    // getters and setters
    getInfo(): string {
        return `The Person's Name: ${this.name}, and Email: ${this.email}`
    }

    setInfo(name: string, email: string) {
        this.name = name
        this.email = email
    }
}

const A = new GoodPerson()
A.LogDetails()

const B = new GoodPerson("Noouuu", "Yesshhh@gmail.com")
B.LogDetails()

console.log(A.city)



// Unlike instance properties, static properties are shared between all instances of a class.

class Employee {
    private static headcount: number = 0;

    private firstName: string
    private lastName: string
    private jobTitle: string
    constructor(
         firstName: string,
         lastName: string,
         jobTitle: string) {

        Employee.headcount++;

        this.firstName = firstName;
        this.lastName = lastName;
        this.jobTitle = jobTitle;
    }

    public static getHeadcount() {
        return Employee.headcount;
    }
}

let john = new Employee('John', 'Doe', 'Front-end Developer');
let jane = new Employee('Jane', 'Doe', 'Back-end Developer');

// console.log(Employee.headcount); //wont work if private so gonna use the method
console.log(Employee.getHeadcount());



// and well we already know what inheritence is and how it works: class Manager extends Employee { constructor(firstname, lastname, jobtitle) { super(firstname, lastname, jobtitle); } }
// super is used here as well.

// Moreover we can implement interfaces in classes.

interface Json {
  toJson(): string;
  name: string;
}

class ABC implements Json {
    private a: string
    private b: string
    public name: string
    constructor(a: string, b: string, name:string) {
        this.a = a;
        this.b = b;
        this.name = name
    }
    toJson(){
        return JSON.stringify({a: this.a, b: this.b});
    }
}

// In the ABC class, we implemented the toJson() method of the Json interface.
// if we implement the interface in a class, we need to implement all the methods of the interface or the variables of the interface.
// This makes sure there is consistency in the code.



// An abstract class is typically used to define common behaviors for derived classes to extend. 
// Unlike a regular class, an abstract class cannot be instantiated directly.

abstract class Vehicle {
    private make: string
    private model: string
    private year: number
    constructor(make: string, model: string, year: number) {
        this.make = make;
        this.model = model;
        this.year = year;
    }
    abstract startEngine(): void;
    abstract stopEngine(): void;
}

class Car extends Vehicle {
    constructor(make: string, model: string, year: number) {
        super(make, model, year);
    }
    startEngine(): void {
        console.log('Engine started');
    }
    stopEngine(): void {
        console.log('Engine stopped');
    }
}
const myCar = new Car('Toyota', 'Corolla', 2020);
myCar.startEngine();
myCar.stopEngine();

// So abstract classes are like a blueprint that another class builds from

// An abstract method does not contain implementation. 
// It only defines the signature of the method without including the method body. 
// An abstract method must be implemented in the derived class.