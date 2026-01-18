# __name__() : dunder methods, about 80-100

'''
__new__ is the method that actually creates the object in memory (whereas __init__ only initializes it)
'''

'''
In Python 3, every single class you create automatically inherits from a built-in class called object. It is the "Great Ancestor" of all types in Python.

class MyClass:
    
is treated as 

class MyClass(object):

print(MyClass.__mro__)
# Output: (<class '__main__.MyClass'>, <class 'object'>)

'''
