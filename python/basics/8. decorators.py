#decorators: tool to allow modify or extend the behavior of functions or classes without changing their structure.
#They are functions that take another function (or method) as an argument and return a new function with the modified behavior.

#Decorators wrap a function using @decorator_name above function

def decorator(func):
    def decorator_method(*args, **kargs):
        print("before func")
        result = func(*args, **kargs)
        print("after func")

        return result 
    return decorator_method

@decorator
def greet(name:str)->None:
    print("hello"+name)

greet("shan")