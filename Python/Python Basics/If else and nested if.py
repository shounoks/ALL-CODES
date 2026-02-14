"""
Syntax   :

if True:
    print("I am right")
else :
    print("I was wrong)
..........
for nested if else syntax is :

if(x==100):
    if(x > 50):
        print("Eitar value thik ache")

"""
x = int(input('Enter a value for x : '))

if x%2 == 0:
    print("x er man jor\n")
else :
    print("x er value bijor\n")


#Nested if else
x = 8
if x%2==0:
    print("Even")

    if x>5:
        print("X is greater than 5 ")
    else:
        print("No it is less than 5 ")

else:
    print("Odd")

#Syntax for else if in python
x = 4
if x == 1 :
    print("One")
elif x == 2 :
    print("Two")
elif x == 3 :
    print("Three")
else :
    print("Ei sob input nibo nah jah betta")
