# Set of design principles in OOP to make software more maintainable, scalable, and easier to understand.
# These principles help developers to write clean, robust, and reusable code.

# **1. S: Single Responsibility Principle (SRP)**
# Each class should focus on a single task or functionality.
# This ensures that the class is easier to understand, test, and modify without affecting other parts of the system.
# => A class should have only one reason to change.
# Benefits:
# - Easy to maintain and understand
# - Easier testing
# - Flexible software
# Example: A class Order with methods: calculate, save_to_db, and send_email. A single class having 3 responsibilities violates SRP.

class Order:  # Correct way
    def __init__(self, items):
        self.items = items

    def calculate_total(self):
        return sum(item['price'] for item in self.items)

class OrderToDB:
    @staticmethod
    def save(order):
        print("Saving to database")

order = [
    {"name": "dosa", "price": 20},
    {"name": "dosa1", "price": 10},
    {"name": "dosa2", "price": 30},
]

ord = Order(order)
print(ord.calculate_total())
OrderToDB.save(order)

# **2. O: Open/Closed Principle (OCP)**
# Software entities (classes, modules, functions) should be **open for extension** but **closed for modification**.
# You should be able to add new functionality without changing existing code.
# Benefits:
# - Maintainability
# - Reusability
# - Adding new features without breaking existing functionality

from abc import ABC, abstractmethod

class Discount(ABC):
    @abstractmethod
    def calculate(self, amount):
        pass

class RegularCustomer(Discount):
    def calculate(self, amount):
        return amount * 0.9

class VIPCustomer(Discount):
    def calculate(self, amount):
        return amount * 0.8

class PremiumCustomer(Discount):
    def calculate(self, amount):
        return amount * 0.7

# Usage
def apply_discount(discount_strategy, amount):
    return discount_strategy.calculate(amount)

reg = RegularCustomer()
vip = VIPCustomer()
prem = PremiumCustomer()

print(f"Regular: {apply_discount(reg, 100)}")
print(f"VIP: {apply_discount(vip, 100)}")
print(f"Premium: {apply_discount(prem, 100)}")

# **3. L: Liskov Substitution Principle (LSP)**
# Objects of a superclass should be replaceable with objects of a subclass without altering the correctness of the program.
# -> Subclasses should behave like their parent class and not break functionality.
# Violation example:
# class Bird:
#     def fly(self):
#         return "I can fly!"
#
# class Penguin(Bird):
#     def fly(self):
#         raise NotImplementedError("Penguins can't fly!")
#
# Problem: Penguin is a bird, but violates behavior expected from a bird. This can break the program if a `Penguin` is substituted for a `Bird` in code that assumes all `Bird` objects can fly.

from abc import ABC, abstractmethod

class Bird(ABC):
    @abstractmethod
    def move(self):
        pass

class FlyingBird(Bird):
    def move(self):
        return "I can fly!"

class NonFlyingBird(Bird):
    def move(self):
        return "I waddle!"

# Using

def observe_bird(bird):
    print(bird.move())

# Substituting FlyingBird and NonFlyingBird
sparrow = FlyingBird()
penguin = NonFlyingBird()

observe_bird(sparrow)  # Output: I can fly!
observe_bird(penguin)  # Output: I waddle!

# **4. I: Interface Segregation Principle (ISP)**
# A class should not be forced to implement interfaces it does not use.
# - Large, multi-purpose interfaces should be split into smaller, more specific ones.
# - This avoids forcing a class to depend on methods it doesn’t need.
# Example: A machine abstract class with abstract methods such as printing, cooling, and heating.
# For a machine like a printer, it’s unnecessary to implement cooling or heating methods, which breaks ISP.

# **5. D: Dependency Inversion Principle (DIP)**
# High-level modules should not depend on low-level modules. Both should depend on abstractions.
# Abstractions should not depend on details. Details should depend on abstractions.
# Benefits:
# - Decoupling: High-level and low-level components are independent of each other.
# - Flexibility: Easily swap out low-level implementations.
# - Testability: Simplifies testing.

from abc import ABC, abstractmethod

class NotificationService(ABC):
    @abstractmethod
    def send(self, message):
        pass

class EmailService(NotificationService):
    def send(self, message):
        print(f"Sending email: {message}")

class SMSService(NotificationService):
    def send(self, message):
        print(f"Sending SMS: {message}")

class NotificationManager:
    def __init__(self, service: NotificationService):
        self.service = service  # Depends on abstraction, not implementation

    def notify(self, message):
        self.service.send(message)

# Usage:
# Use EmailService
email_service = EmailService()
notifier = NotificationManager(email_service)
notifier.notify("Hello via Email!")

# Use SMSService
sms_service = SMSService()
notifier = NotificationManager(sms_service)
notifier.notify("Hello via SMS!")

# Summary:
# - **SRP**: Clear, modular classes.
# - **OCP**: Easy to add features without breaking existing code.
# - **LSP**: Consistent behavior across inheritance hierarchies.
# - **ISP**: Avoid unnecessary dependencies and bloated classes.
# - **DIP**: Decoupled, flexible, and testable systems.
