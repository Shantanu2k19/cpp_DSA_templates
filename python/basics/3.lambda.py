#lambda is a small anonymous function, can take any number of arguments
x = lambda a : a+10

# lambda_name = lambda argument: opration

print(x(5))

#can be used inside function
def func(n):
    return lambda x : x*n

doubler = func(2)
tripler = func(3)

print(doubler(2))
print(tripler(2))
