'''
vehicle: 
drive system

'''
from abc import ABC, abstractmethod

#abstract strategy 
class DriveType(ABC):
    @abstractmethod
    def drive(self):
        pass 

#concrete strategies 
class sportsDrive(DriveType):
    def drive(self):
        print("Sports drive type")

class regularDrive(DriveType):
    def drive(self):
        print("normal drive type")


#BASE CLASS
class Vehicle(ABC):
    def __init__(self, name: str, drive_type:DriveType):
        self.name = name 
        self.drive_type = drive_type

    @abstractmethod
    def describe(self):
        print("A normal car") 

    def drive(self):
        return self.drive_type.drive()
    

#derived class
class SportsCar(Vehicle):
    def describe(self):
        print("sports Car")
    
class regularCar(Vehicle):
    def describe(self):
        return super().describe()



#example usage 
if __name__=="__main__":
    sportDriveStart = sportsDrive()
    regularDriveStrat = regularDrive()

    ferrari = SportsCar("ferrari", sportDriveStart)
    toyota = regularCar("toyota", regularDriveStrat)

    ferrari.describe()
    ferrari.drive()

    toyota.describe()
    toyota.drive()

    