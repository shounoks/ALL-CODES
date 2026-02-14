#Inheritance

class Animal :
    def __init__(self,name):
        self.name = name
        self.is_alive = True
    
    def eat(self):
        print(f"{self.name} is eating")
    
    def sleep(self):
        print(f"{self.name} is sleepig")
    

class Dog(Animal):
    pass

class Cat(Animal):
    pass

class Mouse(Animal):
    pass

dog = Dog("Scooby")
cat = Cat("Oggy")
mouse = Mouse("Jerry")


print(cat.name)
print(cat.is_alive)
cat.eat()
cat.sleep()


print(dog.name)
print(dog.is_alive)
dog.eat()
dog.sleep()
