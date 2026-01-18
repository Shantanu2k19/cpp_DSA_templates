# Decorator Design Pattern is a structural design pattern used to dynamically add new behavior or responsibilities to an object without modifying its existing code
#follows : Open/Closed Principle

from abc import ABC, abstractmethod

# component
class Coffee(ABC):
    @abstractmethod
    def cost(self)->float:
        pass 

    @abstractmethod
    def description(self)->str:
        pass 

#concrete component 
class SimpleCoffee(Coffee):
    def cost(self):
        return 5.0
    
    def description(self):
        return "Simple coffee"


# Decorator class
class CoffeeDecorators(Coffee):
    def __init__(self, coffee: Coffee):
        self._coffee = coffee

    @abstractmethod
    def cost(self)->float:
        pass
    
    @abstractmethod
    def description(self)->str:
        pass


#concrete CoffeeDecorators 
class MilkDecorator(CoffeeDecorators):
    def cost(self)->float:
        return self._coffee.cost()+1.0
    
    def description(self)->str:
        return self._coffee.description() +", milk"
    
class SugarDecorator(CoffeeDecorators):
    def cost(self)->float:
        return self._coffee.cost()+2.0
    
    def description(self)->str:
        return self._coffee.description() +", Sugar"


#usage 
if __name__=="__main__":
    coffee = SimpleCoffee()
    print(f"{coffee.description()} costs {coffee.cost()}")

    coffee = MilkDecorator(coffee)
    print(f"{coffee.description()} costs {coffee.cost()}")

    coffee = SugarDecorator(coffee)
    print(f"{coffee.description()} costs {coffee.cost()}")
