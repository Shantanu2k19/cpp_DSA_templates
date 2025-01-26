
print('---------------------\n')

fruita, fruitb = 'apple', 'banana'
a = b = c = 3

listt = ['a', 2, 'lol']
a,b,c = listt

a = 10  #global var
def lol():
    global kk  #kk is global
    kk = 'global' 
    a = 20 #local, different var
    print(a)

lol()
print(kk)


print('---------------------\n')

aa = [1,2,3,4]
print(aa)
def test():
    #aa = [3,4]  #cannot reassign value of a global variable here, have to use global keyword for reassigning
    global aa
    aa = [3,4]
    print(aa)

test()
    
print('---------------------\n')

x = range(5)
print(x)

# random number
import random
random.range(1,10)  #gives between 1 and 9


x = int('23')



#STRINGS

#splicing 
a = "shan"
print(a[0:1])  #print s   string[a:b], from a to b-1

#modfy string
upA = a.upper()
a.lower()
a.strip() # remove whitespaces from begining and end
a.replace('a','x')
a.split('a')  #shan split into ['sh', 'n'], a not included 

#fstring, print 
a = "shan"
txt = f"my name is {a}"
price = 0.123
txt = f"price is {price:.2f}" #2 decimal places for float 

a.count('an') #gives 1
a.find('ha') #gives index, i.e. 1
a.index('a') #gives 2 



#LIST 

ll= ['a', 'b', 123]
len(ll)
ll = list(('a', 'b', 23.3))
if('a' in ll):
    print("present")
ll[0]='b'
ll[0:5] = ["aa", "bb"]
ll.insert(0, "xx")
ll.append("xx")

ll2 = ["aaaa", 'zzzz']
ll.extend(ll2)  #adds ll2 at the back of ll

ll.remove('banana')
ll.pop(0) # or del ll[0] #removing index
ll.clear()

ok = [x  for x in ll] #copying each element of list 
ok = [x  for x in ll if x>10 ] #with condition
ok = [x if x>2 else "lol" for x in ll]
ll.sort()  
ll.sort(reverse=True)

def myfunc(n):
  return abs(n - 50)
ll.sort(key=myfunc) #custom sort

#sort is case sensitive, Capital comes first, or ignore case by below 
ll.sort(key=str.lower)

ll.reverse()

#list copy 
mylist = ll.copy() #creates shallow copy, reference only

#slice oprator 
list2 = ll[:3]  #n-1 elements from start 0,1,2

list3 = ll+list2 

#list methods=> append(), clear(), copy(), count(ele), extend(), index(), insert(2, 'lol'), pop(0), remove(), reverse(), sort()


####
#TUPLES , ordered, unchangable(immutable), allow duplicates
####

# List is a collection which is ordered and changeable. Allows duplicate members.
# Tuple is a collection which is ordered and unchangeable. Allows duplicate members.
# Set is a collection which is unordered, unchangeable*, and unindexed. No duplicate members.
# Dictionary is a collection which is ordered** and changeable. No duplicate members.

tup = ("a", "b", 123)

if "a" in tup:
    print("yes")

#to extend a tuple, create a list of tuple, then add, then back to tuple, workaround

#tuple can be added to tuple 
tup2 = ("3", 4)

tup3 = tup+tup2
tup3 += tup

var = ("ok") #var is a string 
var = ("ok",) #var is a tuple


#unpacking tuples,
tup = ("a", "b", "c", "d")
(a,*b) = tup  #a is a string 'a', b is a list[b,c,d]

tup*2 #will give a tup of twice the length, tup+tup

#tuple methods: count() #count no of times ele in tuple
#               index() #return position of found index

try:
    index = tup.index('e')
except ValueError:
    print('not found')



#######
# SET 
#######

#unordered, changable, unindexed, duplicates not allowed 

st = {"aaa", "zz", "xx", "bb"}

#True and 1 are same, so is 0 and False
#set is not indexed

stt = {"a", 2, 3}
stt.add("23")

st2 = {"set2"}
st2.update(stt) #adds stt to the st2, update will add any iterable(list etc.)

st2.remove("set2") #raise error if key not found 
st2.discard("set2")  #will not raise error 

del st2 #deletes the set completely, clear() for clearing set 


#joining sets 
#union() and update(), joins all items from both sides, 
#intersection() keeps only duplicates
#difference() keeps item from first set, that are not in other sets 
# symmetric_difference()keeps all items except duplicates

st1 = {1,2,3}
st2 = {3,4,5}

st3 = st1.union(st2) #gives {1,2,3,4,5}
st3 = st1 | st2 #union
# st3 = st1.union(st2, st3,...) #can also union tuples and list 

st1.update(st2) #union and changes the original st1 set 

st3 = st1 & st2 # intersection, st1.intersection(st2)

st3 = st1.difference(st2) #gives 1,2, present in st1 and not in st2
#st3 = st1 - st2

#st1.difference_update(st2) #this will update the original set st1 

st3 = st1.symmetric_difference(st2) #gives {1,2,4,5} #Unique in both 


#set methods: add, clear, copy, difference -, difference_update -=, discard, intersetion &, intersection_uodate() &-,
# issubset(), issuperset() 


######
# DICTIONARIES 
######

#ordered(after python 3.6), changable, no duplicates 
dd = {
    "lol":"abc",
    1:2
}

dd2 = dict(name='lol', age=12, class_=122)
print(dd2)

dd2['name']
dd2.get('name')

dd2.keys()
dd2.values()

if "name" in dd2:
    print("yes")

dd2.update({"name":"lmao"}) #will add new if does not exist

dd["new"] = 123

dd.pop("new") #returns value for key, raise keyError if does not exist 

del dd["new"] #same as pop

# del dd #deletes whole dictionary 

# dd.clear()

for x,y in dd.items():
    print(x,y)

dd2 = dd.copy() # creates a new dictonary entirely
dd2 = dict(dd) #also works 

#######################################

if a>b:
    print("yes")
elif a==b: 
    print("no")
else:
    print("lol")

print("a") if a>b else print("b")    
print("A") if a > b else (print("=") if a == b else print("B"))

if a>b:
    pass

###################
# funcitions 
###################

def func(*args): #arbitary arguments 
    print(args)

func(["a", "b"])



########
# arrays 
#########
#holds same type of data 

import array 
arr = array.array('i', [1,2,3,4]) #i for unsigned integer 
#methods same as list 



print('\n---------------------')


#scope

x = 100
def fun():
    # print(x) would have printed 100
    global x 
    x = 200
    print(x) #prints 200


#nonlocal: nonlocal keyword allows a nested function to modify variables from its enclosing function's scope.

def outrFun():
    x = 100

    def innerClass():
        nonlocal x  # x was readonly, using non local we can change its calue
        x = 200
    
    innerClass()
    print(x)