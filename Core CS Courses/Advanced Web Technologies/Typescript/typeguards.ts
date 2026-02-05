// Type Guards allow you to narrow down the type of a variable within a conditional block.

function echou(value: string | number) {
    if (typeof value === "string") {
        console.log(value.toUpperCase());
    } else if (typeof value === "number") {
        console.log(value.toFixed(2));
    }
}

// this shows the typeof in action
echou("bruh")
echou(10.122)

// There's also instanceof for checking if an object is an instance of a specific class.
// For example, we can check if an object is an instance of the Dog class like this:
class Doggy {
    makeSound() {
        console.log("Woof");
    }
}

class Cat {
    makeSound() {
        console.log("Meow");
    }
}

type Animalz = Doggy | Cat;

function makeSound(animal: Animalz) {
    if (animal instanceof Doggy) {
        animal.makeSound();
    } else if (animal instanceof Cat) {
        animal.makeSound();
    }
}


// then we have the 'in'.
// For example, we can check if an object has a specific property like this:
interface Person2 {
    name?: string;
    age?: number;
}
function hasAge(person: Person2) {
    if("age" in person) {
        return true
    }
    return false
}
console.log(hasAge({ name: "John", age: 30 })); // true
console.log(hasAge({ name: "Jane" })); // false




// Type assertions can be done with 'as' keyword like:
const inputElement = document.getElementById("input") as HTMLInputElement

// or with '<>' keyword like:
const inputElement2 = <HTMLInputElement>document.getElementById("input")