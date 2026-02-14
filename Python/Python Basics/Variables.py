x  = 2
print(x+4)
y =  x +106
print(y)
name =  "Shiv"
print(name)
print(name + " is my love \n" + "I also love Ma Parvati")

print("Address of x variable is  : " ,+ id(x))
#Swaping variable

#Methood 0

a = 10
b = a
print(a)
print(b)
print("Id of a is : ", + id(a))
print("Id of b is  : ", + id(b))

aa = 220
print("Before : ", + id(aa))
aa = 223
print("After : ", + id(aa))

PI =  3.1416
print(type(PI))

#Methood 1
a = 5
b = 6
temp = a
a = b
b = temp

print("a : ",a)
print("b : ",b)
print("\n")

#Methood 2
a = 5
b = 6
a = a+b
b =a-b
a = a-b

print("a : ",a)
print("b : ",b)
print("\n")

#Methood 3
a = 5
b =6

a = a^b
b = a^b
a = a^b

print("a : ",a)
print("b : ",b)
print("\n")

#Methood 4

a = 5
b = 6

a,b = b,a

print("a : ",a)
print("b : ",b)
print("\n")



