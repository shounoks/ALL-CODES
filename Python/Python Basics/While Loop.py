#Here we will print a same string again and again using while loop
i = 1
while i<=5:
    print("har Har Mahadev\n")
    i=i+1

# Or, we can also do this....

i = 5
while(i>=1):
    print("Shiv Parvati")
    i = i-1

i = 0
while(i<=10):
    print("Mahadev is My friend ", i)
    i = i+1

#Nested while loop
i = 1
j = 1
while(i<5):
    print(" Shiv \n")

    while(j<=4):
        print("Mahadev \n")
        j=j+1

    i = i+1

#Let's print Mahadev and Shiv in a same line

while i <=5:

    print("Shiv ", end ="")
    while j<=4:
        print("Mahadev ", end="")
        j =j+1
    i=i+1