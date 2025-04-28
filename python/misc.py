import random
print(random.random())  #random float between 0 and 1
print(random.randrange(0,100))  #random between 0 and 100



########### try except

ll = [1,2,3]
try: 
    print(ll[1])
except NameError:
    print("name error")
except:
    print("some error")
else:
    print("Nothing went wrong")
finally:
    print("will execute finally regardless")    


x = -1
# if x<0:
#     raise Exception("below zero!!")

class MyException(Exception):
    pass

if 0:
    raise MyException("This is a custom exception!")


class myExceptionWithMssg(Exception):
    def __init__(self, age, message="age must be betweeb 18 and 60"):
        self.age = age
        self.message = message
        super().__init__(f"{message}: provided : {age}")


if 1:
    raise myExceptionWithMssg(12)