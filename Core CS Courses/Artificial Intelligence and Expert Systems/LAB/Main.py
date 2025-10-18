import os  
os.system('cls' if os.name == 'nt' else 'clear')

# first = "Bro"

# print(f"Hello, {first} !")

# gpa = 3.98
# print(f"Your GPA is {int(gpa)}") # 3
# print(f"Your GPA is {gpa}") # 3.98

# name = input("Enter your name: ")
# age = int(input("Enter your age: "))

# print(f"Hello, {name} !") 
# print (f"You are {age} years old.")
# print(f"Next year, you will be {age+1} years old.")

x = 4
y = 3
z = 15
# power1 = x ** 3
# power2 = pow(x, 3)
# print(power2)

# print(max(x, y, z))
# print(min(x, y, z))

# We have various other math functions like abs, round, floor, ceil, etc.
# We can use the math module to access these functions.
# import math
# print(math.sqrt(16))
# print(math.floor(3.9))
# print(math.ceil(3.1))
# print(math.pow(2, 3))
# print(math.pi)
# print(math.e)
# print(math.inf)
# print(math.nan)
# print(round(3.512121, 2)) # 3.51

# We also have % operator which gives the remainder of the division.
# print(10 % 3) # 1
# print(10 % 2) # 0



# def Suggest_Clothes(temp):
#     if temp >= 50: #the order of the conditions is important # if we put this condition at the end, it will never be executed # because the previous condition will be executed first
#         return "INVALID, TEMPERATURE TOO HIGH"
#     elif temp >= 30:
#         return "Wear light clothes"
#     elif 20 <= temp < 30:
#         return "Wear a T-shirt"
#     elif temp > 10:
#         return "Wear a jacket"
#     else:
#         return "Wear a coat"

# temp = int(input("Enter the temperature (celcius): "))
# print(Suggest_Clothes(temp))

# logical operators
# and, or, not 
# They are used to combine multiple conditions.
# and: returns True if all conditions are True 
# or: returns True if at least one condition is True 
# not: returns the opposite of the condition like True -> False, False -> True

# conditional expressions
# x = 4 if 3 > 2 else 5
# print(x) # 4  #basically it is a shorthand for if else statement, X if condition else Y

# Here are some string methods (use them like name.method())
#  len() # these are used to get the length of the string. This counts the spaces as well, and from 1 not 0
#  _sizeof_() # these are used to get the size of the string in bytes
#  capitalize() # these are used to capitalize the first letter of the string
#  upper() # these are used to convert the string to uppercase or lowercase
#  lower() # these are used to convert the string to uppercase or lowercase
#  title() # these are used to capitalize the first letter of each word
#  swapcase() # these are used to swap the case of the string
#  strip() # these are used to remove the spaces
#  lstrip() # these are used to remove the spaces
#  rstrip() # these are used to remove the spaces
#  count() # these are used to count the number of times a substring appears in the string
#  find() # these are used to find the index of the string, this counts from 0
#  rfind() # these are used to find the index of the string, This counts from the end
#  index() # these are used to find the index of the string
#  rindex() # these are used to find the index of the string
#  startswith() # these are used to check the string
#  endswith() # these are used to check the string
#  isalnum() # these are used to check the string
#  isalpha() # these are used to check the string
#  isdigit() # these are used to check the string
#  islower() #  these are used to check the string
#  isupper() # these are used to check the string
#  isspace() # these are used to check the string
#  split() # these are used to split the string, example split(" ") will split the string at the spaces, split(",") will split the string at the commas.
#  rsplit() # these are used to split the string
#  replace() # these are used to replace the string
#  format() # these are used to format the string
#  format_map() # these are used to format the string
#  encode() # these are used to encode the string
#  zfill() # these are used to fill the string with zeros
#  partition() # these are used to partition the string
#  rpartition() # these are used to partition the string
#  expandtabs() # these are used to expand the tabs
#  translate() # these are used to translate the string
#  maketrans() # these are used to make a translation table
#  splitlines() # these are used to split the string at the line breaks
#  join() # these are used to join the strings
#  rjust()  # these are used to justify the string to the left or right
#  center() # these are used to center the string
#  ljust()  # these are used to justify the string to the left or right



# Format Specifiers in Python are used to format the output. {value:flags}

# price1 = 3.14159
# price2 = -987.65
# price3= 12.34

# print(f"Price 1 is ${price1:.2f}") # 2 decimal places
# print(f"Price 2 is ${price2:10}") # 10 spaces
# print(f"Price 3 is ${price3:<10}") # left justified
# print(f"Price 3 is ${price3:>10}") # right justified
# print(f"Price 3 is ${price3:^10}") # center justified
# print(f"Price 3 is ${price3:010}") # fill with zeros

# price4 = 3000.14159

# print(f"Price 4 is ${price4:+,.2f}") # comma separated, 2 decimal places, + sign



# While Loop
# name = input("Enter your name: ")
# while name == "":
#     print("Please enter your name")
#     name = input("Enter your name: ")
# print(f"Hello, {name} !")


# name = input("Enter your name (or type 'quit' to exit): ")
# while name != "quit":  # Type "quit" to exit the loop
#     print(f"Hello, {name} !")
#     name = input("Enter your name: ")

# print("Goodbye!")

# For Loop
# for i in range(5): # 0 to 4   # range(5) is equivalent to range(0, 5)
#     print(i)
# for i in range(1, 5): # 1 to 4    
#     print(i)
# for i in range(1, 10, 2): # 1 to 9, step 2
#     print(i)
# for i in range(10, 1, -1): # 10 to 2, step -1
#     print(i)
# for i in reversed(range(5)): # 4 to 0
#     print(i)
# for i in reversed(range(1, 5)): # 4 to 1
#     print(i)

# num = 123456789
# for x in str(num):
#     print(x)

# for x in range(1,21):
#    if x == 13:
#        continue/break
#    else:
#       print(x)

# for x in range(1,21):
#   print(x, end="") # 1234567891011121314151617181920

# # Positional arguments: These are the most common type of arguments and are passed to the function in the correct positional order.
# def greet(name, age):
#     print(f"Hello, {name}! You are {age} years old.")

# greet("Alice", 30)  # Positional arguments

# # Default arguments: These arguments take a default value if no value is provided during the function call.
# def greet(name, age=25):
#     print(f"Hello, {name}! You are {age} years old.")

# greet("Bob")  # Default argument for age
# greet("Charlie", 35)  # Overriding the default argument

# # Keyword arguments: These arguments are passed to the function by explicitly specifying the parameter name.
# def greet(name, age):
#     print(f"Hello, {name}! You are {age} years old.")

# greet(name="David", age=40)  # Keyword arguments
# greet(age=45, name="Eve")  # Order doesn't matter with keyword arguments

# # Arbitrary arguments: These arguments allow you to pass a variable number of arguments to a function. They are defined using *args and **kwargs.
# def greet(*names):
#     for name in names:
#         print(f"Hello, {name}!")

# greet("Frank", "Grace", "Hank")  # Arbitrary positional arguments

# def greet(**person):
#     print(f"Hello, {person['name']}! You are {person['age']} years old.")

# greet(name="Ivy", age=50)  # Arbitrary keyword arguments


# MATCH CASE STATEMENT
# def day_of_week(day):
#     match day:
#         case "Monday":
#             print("It's Monday!")
#         case "Tuesday":
#             print("It's Tuesday!")
#         case "Wednesday":
#             print("It's Wednesday!")
#         case "Thursday":
#             print("It's Thursday!")
#         case "Friday":
#             print("It's Friday!")
#         case "Saturday":
#             print("It's Saturday!")
#         case "Sunday":
#             print("It's Sunday!")
#         case _:
#             print("Invalid day!")

# CLASSES:
# class Student:
#     class_year = 2025
#     def __init__(self, name, age):
#         self.name = name
#         self.age = age

#     def greet(self):
#      print(f"Hello, {self.name}! You are {self.age} years old.")

# student1 = Student("Alice", 20)
# student2 = Student("Bob", 25)
# student1.greet()
# student2.greet()




# Magic methods (also called dunder methods because they have double underscores __ before and 
# after their names) are special methods in Python that allow objects to define their behavior in built-in operations 
# like arithmetic, comparisons, string representation, and more.
# Common Magic Methods:
# 1. Object Initialization & Representation
# __init__(self, ...) → Constructor, initializes an instance.
# __str__(self) → String representation for str(obj).
# __repr__(self) → String representation for debugging (repr(obj)).
# 2. Arithmetic Operations
# __add__(self, other) → Defines self + other.
# __sub__(self, other) → Defines self - other.
# __mul__(self, other) → Defines self * other.
# __truediv__(self, other) → Defines self / other.
# __floordiv__(self, other) → Defines self // other.
# __mod__(self, other) → Defines self % other.
# 3. Comparison Operators
# __eq__(self, other) → Defines self == other.
# __ne__(self, other) → Defines self != other.
# __lt__(self, other) → Defines self < other.
# __le__(self, other) → Defines self <= other.
# __gt__(self, other) → Defines self > other.
# __ge__(self, other) → Defines self >= other.
# 4. Attribute Access & Management
# __getattr__(self, name) → Defines behavior for accessing non-existent attributes.
# __setattr__(self, name, value) → Defines behavior for setting attributes.
# __delattr__(self, name) → Defines behavior for deleting attributes.
# 5. Container & Sequence Methods
# __len__(self) → Defines len(self).
# __getitem__(self, key) → Defines self[key].
# __setitem__(self, key, value) → Defines self[key] = value.
# __delitem__(self, key) → Defines del self[key].
# 6. Object Call & Iteration
# __call__(self, *args, **kwargs) → Allows an instance to be called like a function.
# __iter__(self) → Defines iteration behavior (for x in obj).
# __next__(self) → Defines next(obj).

# Example Usage:
# class Point:
#     def __init__(self, x, y):
#         self.x = x
#         self.y = y

#     def __add__(self, other):
#         return Point(self.x + other.x, self.y + other.y)

#     def __str__(self):
#         return f"Point({self.x}, {self.y})"

# p1 = Point(2, 3)
# p2 = Point(4, 5)
# p3 = p1 + p2  # Calls __add__
# print(p3)     # Calls __str__: Output -> Point(6, 8)


# Getter and Setter Methods
# class Student:
#     def __init__(self, name, age):
#         self._name = name
#         self._age = age
#    @property
#     def get_name(self):
#         return self._name
#     @name.setter
#     def set_name(self, name):
#         self._name = name
#     @property
#     def get_age(self):
#         return self._age
#     @age.setter
#     def set_age(self, age):
#         self._age = age
# student = Student("Alice", 20)
# print(student.get_name())  # Alice
# student.set_name("Bob")
# print(student.get_name())  # Bob
# print(student.get_age())  # 20
# student.set_age(25)
# print(student.get_age())  # 25


# Exception handling in Python allows you to gracefully handle errors that may occur during program execution, preventing crashes and providing meaningful error messages.

# 1. What is an Exception?
# An exception is an error that occurs during program execution, stopping normal flow. Examples include:

# ZeroDivisionError: Division by zero.
# TypeError: Invalid operations between data types.
# FileNotFoundError: Accessing a missing file.


# 2. Handling Exceptions Using try-except
# Python provides the try-except block to catch and handle exceptions.

# try:
#     num = int(input("Enter a number: "))
#     result = 10 / num
#     print("Result:", result)
# except ZeroDivisionError:
#     print("Error: Cannot divide by zero.")
# except ValueError:
#     print("Error: Please enter a valid number.")
# except Exception as e:
#     print(f"Unexpected error: {e}")

# How it works:
# Code inside try runs normally.
# If an exception occurs, it jumps to except, handling the error.
# except Exception as e catches any unexpected errors.



# 3. Using finally for Cleanup
# The finally block always executes, even if an exception occurs. It is used for cleanup tasks like closing files or network connections.
# try:
#     file = open("data.txt", "r")
#     content = file.read()
# except FileNotFoundError:
#     print("File not found.")
# finally:
#     print("Closing the file.")
#     file.close()


# 4. Raising Custom Exceptions (raise)
# You can manually raise exceptions using raise.

# def withdraw(amount):
#     if amount > 1000:
#         raise ValueError("Withdrawal limit exceeded!")
#     print(f"Withdrew {amount}")

# try:
#     withdraw(1500)
# except ValueError as e:
#     print(f"Transaction failed: {e}")


# 5. Custom Exception Classes
# You can define your own exception types by inheriting from Exception.

# class InsufficientFundsError(Exception):
#     pass

# def withdraw(balance, amount):
#     if amount > balance:
#         raise InsufficientFundsError("Not enough funds.")
#     print(f"Withdrew {amount}")

# try:
#     withdraw(500, 1000)
# except InsufficientFundsError as e:
#     print(f"Error: {e}")



