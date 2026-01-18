#any file with .py extension is a module

# import funcName from moduelName as alias

# list all the function names in module: dir()
import random 

x = dir(random)
# print(x)


#datetime

import datetime

x = datetime.datetime.now()
print(x)
print(x.strftime("%A")) #weekday

x = datetime.datetime(2025, 5, 7)
print(x)


#####################


import json

src = '{"name":"sh", "age":21, "city":"delhi"}'

opJson = json.loads(src)

print(opJson["name"])

jsonStr = json.dumps(opJson)
print(jsonStr)
print(type(jsonStr))




#########################
import re 

txt = "The rain in Spain"
x = re.search("^The.*Spain$", txt)

