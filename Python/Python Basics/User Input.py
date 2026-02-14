#In our previous types ar we had used many types of functions like 'print','math'.
#To get input we will use input function

x  = input() #Basic syntax of input(By default charrecter data type)
y = input()
z  = x+y
print(z)

x = input("Enter the value of x : ")

#Specific type of input
x = input("Enter x : ")
a = int(x)
y = input("Enter y : ")
b = int(y)

c = a+b
print(c)

#We also can do in a short way

x = int(input("Enter x : "))

print(x)

#Specific charrecter

#We will take input from the users in a char format to do this
ch  = input('Enter a Charrecter : ')
print(ch)

cha  = input("Enter a char : ")
print(cha)

#Here we also can use index number, when we wanna see only a special charrecter like string
ch = input('Enter a charrecter : ')
print(ch[0])

#We also can do this in another way like this.....
ch = input("enter a char")[0]

#We also can evaluate the value by using eval function....
result  = eval(input('Enter a expression : '))
print(result)
#Input sample : 21-45+8*6

x = str(input("Enter string : "))
print(x)




