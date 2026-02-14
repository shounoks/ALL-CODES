num=[20,30,108,424,979,232,242]
print(num)
num1 = [9.5,108,'Shiv','Parvati']
print(num1)

NumNum= len(num)
print(" Length of the list is : ", + NumNum )

x = [10,20,180,1,6,566]
y= ['AA','BB','CC']
z = [x,y]
print(z)

print("\n")

x.append(45)
print(x)

x.insert(2,1008)
print(x)

x.remove(1008)
print(x)

x.pop(0)
print(x)

x.pop()
print(x)

del x[2:]
print(x)

x.extend([221,1008,620])
print(x)

print("Min is : ",+min(x))

print("Max is : ",+max(x))

print("Sum of the elements is : ", + sum(x))

X_variable = x.sort()

print(X_variable)

# User input in list
x = []
print("Enter the elements : \n")
for i in range(5):
    x.append(int(input(f"Enter {i}th value : ")))
print("The list is : \n",x+1)


