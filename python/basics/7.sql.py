import mysql.connector

mydb = mysql.connector.connect(
    host="localhost",
    user="root",
    password="123",
    database="mydb"
)

mycursor = mydb.cursor()

mycursor.execute("Select * from customer")

result = mycursor.fetchall()

for x in result: 
    print(x)