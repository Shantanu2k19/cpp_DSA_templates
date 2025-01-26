def func(*args): #arbitrary arguments
    print(args)

func(["a", "b"])


def func2(a, b, c):
    print(a,b,c)

func2(a=1, c=10, b=69) #will maintain name

def func3(**kwarg): #arbitrary keywords arguments 
    print(kwarg["a"])

func3(a=1, b=10, c=100)

def func4(a, b, /): # / means only positional arguments can be passed, no keyword arguments
    print(a,b)
#func4(a=1,b=2) #throws error 

# def func4(*, a, b): # * specifies keyword arguments only 

def func5(a, b, /, *, c, d): #combine positional and keyword arguments 
    print(a,b,c,d)

func5(1,2,c=3,d=4)


