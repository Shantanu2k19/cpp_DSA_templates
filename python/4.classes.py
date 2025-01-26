class stud: 
    name = "default_name"

    def __init__(self, name, age): # self is a reference to the current instance of the class
        print(self.name)
        self.name = name
        self.age = age
    
    def __str__(self):
        return f"The student {self.name} is of age {self.age}"
    
    def fun(self):
        print(f"hello from {self.name}")
    # a function is a method, it can be instance method(self in argument) or a class method or static method 

c1 = stud("shan", 23)
print(c1)
print(c1.name)
del c1.name # name reverted back to original
c1.fun()
del c1

print("____________")


class Animal:
    def __init__(self, name, species):
        self.name = name
        self.species = species  
        #Attributes assigned to self are stored in the instance's __dict__, 
        #which is the underlying storage for instance-specific data.
    def describe(self):
        return f"animal class: name:{self.name} species:{self.species}"
    
dog = Animal("lucy", "dog")
print(dog.__dict__)
#1. creating class and objects

class bank:
    def __init__(self, owner, balance):
        self.owner = owner
        self.__balance = balance #__ makes attribrute private, Internally becomes _bank__balance
    #python changes the name of attribrute to _ClassName__attributeName
    
    #Use getter and setter methods to safely access or modify private attributes
    def get_balance(self):
        return self.__balance
    
    def deposit(self, amount):
        self.__balance+=amount

# 2.Encapsulation in action, restricting access to private attribrute, controlled access using getters and setters 
bankObj = bank("shan", 1000)
print(bankObj._bank__balance) #not recommended to access private attribrute using mangled name

print("____________")



# 3. Inheritance
class dog(Animal):
    def __init__(self, name, breed):
        super().__init__(name, "Dog")
        self.breed = breed
        
    def describe(self):
        return f"dog class: {self.name} is a {self.breed}"

labrador = dog("max", "labra")
print(labrador.describe())


print("____________")

# MRO:  Method Resolution Order-> the order in which Python looks for a method or attribute in a class hierarchy when it is called.  especially important in cases of multiple inheritance
#Python uses the C3 Linearization algorithm to calculate MRO for classes.
#print(className.mro())

#polymorphism, objects of different classes to be treated as objects of a common superclass, dog and cat both inherit from Animal, but have their own describe method 
# common interface (Animal.describe) while allowing different classes (Dog, Cat) to implement their own specific behavior.

#simple example: len() can be used for string, list etc. Different classes can have same method name, child classes override parent class method,
class cat(Animal):
    def __init__(self, name):
        super().__init__(name, "cat")
        
animals = [dog("buddy", "pug"), cat("whiskers")]
for animal in animals:
    print(animal.describe())

    
# 5. Abstraction: hiding complex implementation details and exposing only essential features

#abstract method: method declared in a abstract class but does not provide concrete implememntation, and subclasses must override these methods to be instantiated.

#@abstractmethod decorator: provided by abc(abstract base class) module, when used makes a method as abstract. 

from abc import ABC, abstractmethod

class Shape(ABC):  # Abstract class, since inherited from ABC
    @abstractmethod
    def area(self):  # Abstract method
        pass

# concrete subclass: a concrete subclass is regular class that extends abstract class and provide implementations for all the abstract methods
#abstract class cannot be instantiated, but concrete class can be. 


class Reactangle(Shape):   # Concrete subclass
    def ___init__(self, width, height):
        self.width = width
        self.height = height
        
    def area(self):  # Implementing the abstract method
        return self.width*self.height

print("____________")

# To create an object/class as an iterator you have to implement the methods __iter__() and __next__() to your object.

class MyNumber:
    def __iter__(self):
        self.a = 1
        return self
    
    def __next__(self):
        x = self.a
        
        if(x>2):
            raise StopIteration  #for stopping after a limit

        self.a+=1
        return x
    
myObj = MyNumber()
itr = iter(myObj)

for x in itr:
    print(x)

# print(next(itr))
# print(next(itr))

print("____________")

#set, list, string all have iter method implemented
s = "shantanu"
itr = iter(s)
print(next(itr))
print(next(itr))
print(next(itr))
print(next(itr))

print("____________")



#######################
# GENERATORS
#######################
#generators are way to create iterators in a more concise and mempry efficient menner.
#generator allow you to iterate over large dataset without needing to store dataset in memory

#defined like a regular function, but uses yield instead of return
#each time yield is called, function state is saved, allowing to resume from where it left

#returns a generator object, next can be used or can do looping

#produces item ondemand, makes them memory efficient, expecially for large datasets 

def simple_gen():
    yield 1
    yield 2
    yield 3

gen = simple_gen()

print(next(gen))
print(next(gen))

print("____________")


def countUptoN(n):
    i=0
    while i<n:
        yield i 
        i+=1


for number in countUptoN(5):
    print(number)

#advanatges: memory efficient: yield one item at a time (ex: generating first million numbers without storing)
#infinite sequence : generate fibonacci number, prime number etc. without storing
print("____________")

def fibonacci():
    a=0
    b=1
    while True:
        yield a
        temp = a
        a = b
        b = temp+b

fib_gen = fibonacci()
for _ in range(10):
    print(next(fib_gen))



#a, b = b, a + b    -> tuple unpacking
#update multiple variables simultaneously without losing their original values during computation
#a=1,b=2, RHS = (2, 1+2) => (2, 3)
# a,b = (2,3)
    

# dunder __name__ is a special built-in variable in Python that represents the name of the current module. 
# #It helps in determining whether a Python script is being run as the main program or 
# being imported as a module in another script.

def greet():
    print("Hello, World!")

if __name__ == "__main__":
    greet()  # This will run only if the script is executed directly