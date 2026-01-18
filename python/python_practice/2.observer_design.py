from abc import ABC, abstractmethod

#observer interface 
class weatherObserver(ABC):
    @abstractmethod
    def gotUpdate(self, temp, humid):
        pass

#concrete observers 
class TVobserver(weatherObserver):
    def gotUpdate(self, temp, humid):
        print(f"TV report: temp:{temp}, humidity:{humid}")

class MobileObserver(weatherObserver):
    def gotUpdate(self, temp, humid):
        print(f"Mobile report: temp:{temp}, humidity:{humid}")       



# broadcast/subject interface 
class Broadcaster(ABC):
    @abstractmethod
    def addListner(self):
        pass 

    @abstractmethod
    def delListner(self):
        pass

    @abstractmethod
    def broadcast(self):
        pass 

#concrete subject
class wetherBroadcaster(Broadcaster):
    def __init__(self):
        self._observer_list = []
        self._temprature = 0
        self._humidity = 0

    def addListner(self, observer_:weatherObserver)->None: #return type can be addedd for all methors
        self._observer_list.append(observer_)

    def delListner(self, observer_:weatherObserver)->None:
        self._observer_list.remove(observer_)

    def broadcast(self)->None:
        for observer in self._observer_list:
            observer.gotUpdate(self._temprature, self._humidity)
    
    def setDataForBroad(self, temp, humid)->None:
        self._temprature = temp
        self._humidity = humid 
        self.broadcast()


if __name__=="__main__":
    tvListner = TVobserver()
    mobileListner = MobileObserver()

    weatherApi = wetherBroadcaster()
    weatherApi.addListner(tvListner)
    weatherApi.addListner(mobileListner)

    weatherApi.setDataForBroad(25, 95)
        