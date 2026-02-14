def add(n1,n2):
    return n1 + n2

x = int(input("Enter x : "))
y = int(input("Enter y : "))
print("Result is : ",add(x,y))

def add_number(num):

    result = 0

    for num in num:
        result = result+num
    return result

result = add_number([1,2,30,4,5,9])
print("Sum of the elements of the list is : ",result)

def add_list(lis):
    result = 0
    for lis in lis:
        result = result + lis
    return result

def avg_list(liss,size):
    res = 0
    for liss in liss:
        res += liss
        avg = res / size
    return   avg


lis1 = []
size_of_list = int(input("Enter the size of the list :"))
i = 0
while (i < size_of_list):
    lis1.append(int(input(f"Enter {i + 1}th element : ")))
    i = i + 1

sums = add_list(lis1)
print(f"Sum of the list elements :  {sums}")
avgs = avg_list(lis1,size_of_list)
print(f"Average of the list elements is : {avgs:.4f}")

"""def add_list(lis):
    result = 0
    for lis in lis:
        result = result + lis
    return result

def avg_list(liss,size):
    res = 0
    avg = 0
    for liss in liss:
        res += liss
        avg = res / size
    return   avg

size_of_list = int(input("Enter the size of the list :"))
lis1 = []

for i in range(size_of_list) :
    lis1.append(int(input(f"Enter {i + 1}th element : ")))


sums = add_list(lis1)
print(f"Sum of the list elements :  {sums}")
avgs = avg_list(lis1,size_of_list)
print(f"Average of the list elements is : {avgs:.4f}")
"""
"""def namta(n):
    for i in range(11):
        result = i * n
        print(f"{n} X {i} = {result}")

number = int(input("Enter a number to see namta : "))
re = namta(number)
"""





