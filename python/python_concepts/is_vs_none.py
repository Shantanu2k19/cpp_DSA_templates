"""
None is singelton, there is only one None
is checks the object identity, not value 


== : compares meaning,not memory 

s1 == s2 # where s1 and s2 are class objects 
Checks logical equality, defined by __eq__.
If __eq__ is not defined, Python falls back to identity → behaves like is
If __eq__ is defined, it compares meaningful attributes


"""


####################

'''
if using == eq is in effect (gives True, True)
if using is, simply compares memory (gives True, False)
'''
class A:
    def __eq__(self, other):
        return True

s1 = A()
s2 = s1
s3 = A()

print(s1 is s2)   # True  (same object)
print(s1 is s3)   # False (different objects)

print(s1 == s2)   # True  (same object)
print(s1 == s3)   # False (different objects)

####################

