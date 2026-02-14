
  # Class Variable : 
    #             Defined outside the constructor
    #             Shared among all instances of a class
    #             Allow you to share data among all objects created from that class 


class Student :

    class_year = 2027 #class variable
    num_of_students = 0

    def __init__(self,name,age):
        self.name = name
        self.age = age
        Student.num_of_students += 1

student1 = Student("Ghost",30)
student2 = Student("Petni",25)
student3 = Student("Pet",25)

print(student2.name)
print(student2.age)
print(Student.class_year)
print("\n")

print(Student.num_of_students)

print(f"My graduating class of{Student.class_year} has {Student.num_of_students} students ")
print()