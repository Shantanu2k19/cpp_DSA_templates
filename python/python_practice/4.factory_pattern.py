#privides interface for creating objects, but 
# actual object creation is left to subclasses. 

# The goal is to define a method that creats objects 
# of a particulat type but without specifying the exact class
# of object that will be created 

from abc import ABC, abstractmethod

#Product
class Animal(ABC):
    @abstractmethod
    def speak(self):
        pass

#Concrete products 
class Dog(Animal):
    def speak(self)->str:
        return "woof woof"

class Cat(Animal):
    def speak(self):
        return "meow meow"
    
#Factory (Creator)
class AnimalFactory:
    def create_animal(self, animal_type:str)->Animal:
        if animal_type=="dog":
            return Dog()
        elif animal_type=="cat":
            return Cat()
        else:
            raise ValueError("Unknown animal type")



#usage 
factory = AnimalFactory()
dog = factory.create_animal("dog")
cat = factory.create_animal("cat")

print(dog.speak())
print(cat.speak())
            

'''
        +------------------+             
        |  AnimalFactory   |           
        +------------------+             
        | + create_animal()|            
        +------------------+             
                |
    +--------------------+------------------+
    |                                    |
+------------+                      +------------+
|   Dog      |                      |   Cat      |
+------------+                      +------------+
| + speak()  |                      | + speak()  |
+------------+                      +------------+

'''
    

