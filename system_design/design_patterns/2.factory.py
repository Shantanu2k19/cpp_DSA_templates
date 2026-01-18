'''
Creates object without exposing creation logic 

use cases: 
1. Payment gateways 
2. DB querry with multiple DBs

'''

class Sql:
    def __init__(self):
        print("Sql db")

class Mongo:
    def __init__(self):
        print("Mongo db")

class dbFactory:
    @staticmethod 
    def select_db(db_type):
        if db_type == "mysql":
            return Sql()
        elif db_type == "mongo":
            return Mongo()


# using 
db_conn = dbFactory.select_db("mysql")