#Used to create objects without specifying their 
# concrete classes

#provides interface for creating set of related 
#objects but leaves instantiation of each indicvidual
#object to concrete factories.

from abc import ABC, abstractmethod


#Abstract products 
class Button(ABC):
    @abstractmethod
    def render(self):
        pass

class CheckBox(ABC):
    @abstractmethod
    def render(self):
        pass


#concrete products
class WindowButton(Button):
    def render(self):
        return "Rendering windows button"
    
class WindowsCheckBox(CheckBox):
    def render(self):
        return "Rendering windowd checkBox"
    
#concrete products 
class MacButton(Button):
    def render(self):
        return "Rendering Mac Button"
    
class MacCheckBox(CheckBox):
    def render(self):
        return "Rendering mac CheckBox"
    

#Abstract Factory 
class GUIFactory(ABC):
    @abstractmethod
    def create_button(self)->Button:
        pass

    @abstractmethod
    def create_checkbox(self)->CheckBox:
        pass 

#Concrete factory for Windows
class WindowsFactory(GUIFactory):
    def create_button(self)->Button:
        return WindowButton()
    
    def create_checkbox(self):
        return WindowsCheckBox()
    
class MacFactory(GUIFactory):
    def create_button(self):
        return MacButton()
    
    def create_checkbox(self):
        return MacCheckBox()
    



#USAGE 
def client_code(factory: GUIFactory):
    button = factory.create_button()
    checkbox = factory.create_checkbox()

    print(button.render())
    print(checkbox.render())



#client using windows factory 
windows_factory = WindowsFactory()
client_code(windows_factory)

mac_factory = MacFactory()
client_code(mac_factory)


"""
Abstract Products (Button, Checkbox) define common methods.
Concrete Products (e.g., WindowsButton, MacButton) implement the methods for different families.
Abstract Factory (GUIFactory) provides methods for creating abstract products.
Concrete Factories (WindowsFactory, MacFactory) implement methods to create concrete products (specific to their family).
"""