'''
3 types of methods in python 
class, instance and static
'''


class Car:
    counter = 0

    def __init__(self, brand, speed):
        self.brand = brand
        self.speed = speed

    #1. Instance method, object specific, can acccess and modify instance variables, first parameter is always self 
    def accelerate(self):
        self.speed = self.speed + 10
        Car.counter += 1   # global class level variable 
        self.counter += 1   # instance level variable 
        print(f"accelerate")

    #2. Class method, first parameter is always cls, work with class itslef not individual objects 
    @classmethod 
    def change_counter(cls, number):
        cls.counter = number

    #3. static methods, do not use self or cls, defined using @staticmethod decorator
    def add(a,b):
        return a+b


#1. instance example
c = Car("Toyota", 100)
c2 = Car("Honda", 100)
print(c.counter)
c.counter = 100  # instance level variable 
print(Car.counter)
print(c2.counter)  # instance level variable, overshadows class variable, this is different from Car.counter
c.accelerate()
print(c.counter)
print(Car.counter)

#class variable can be accessed using instance variable : c.__class__.counter = 10
print("=="*20,)

#2. Class variable example 
Car.change_counter(169)
print(Car.counter)

print("=="*20,)

#3. Static method example
print(Car.add(10, 20))



