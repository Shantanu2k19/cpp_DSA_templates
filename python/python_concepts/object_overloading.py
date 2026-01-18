'''
ability to define how standard python operators behave when they are used with custom objects 


a+b(a and b a are objects), python look for dunder method, __add__ to perform the operation

other oprations : __sub__, __mul__ etc
'''

class A:
    def __init__(self, x):
        self.x = x
    
    def __add__(self, other_class_obj):
        return self.x + other_class_obj.x

a = A(10)
b = A(20)
print(a+b)