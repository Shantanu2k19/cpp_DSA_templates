'''
ensure only one instance of a class exist. 
in __new__ dunder method, we can check if instance was created and saved as class object, if yes, return it 

used when : 
1. Logger
2. Database connection pool
3. Cache 

'''

class Singelton:
    _instance = None

    def __new__(cls): #__new__ is the method that actually creates the object in memory (whereas __init__ only initializes it).
        if cls._instance is None:
            cls._instance = super().__new__(cls)
        return cls._instance

    def __init__(self):
        if self._instance is not None:
            raise Exception("This class is a singleton!")
        self._instance = self

s1 = Singelton()
s2 = Singelton()
print(s1 is s2)