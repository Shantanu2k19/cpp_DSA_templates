# r-Read, a-append, w-write(create if not exist), x-create
# t-text, b-binary
f = open("demo.txt") #default rt read text
print(f.read())

print(f.readline())
print("-")
f.close()

f = open("demo.txt","a")
f.write("new text added")
f.close()

f = open("demo.txt", "r")
for x in f:
    print(x)

print("-")

import os 
if os.path.exists("demofile.txt"):
  os.remove("demofile.txt")
else:
  print("The file does not exist")

# os.rmdir()

with open("demo.txt", "r") as f:  # Auto-closes file
    for x in f:
        print(x.strip())  # Remove extra newlines