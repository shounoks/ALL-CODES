import matplotlib.pyplot as plt

x =[1,2,3,4,5]
y1 = [4,12,28,52,80]
x =[1,2,3,4,5]
y2 = [-3.2,16,35.2,54.4,73.6]

a1,b1 = 1,4
a2,b2 = 5,80

plt.xlabel("Months",color = 'red')
plt.ylabel("Videos ",color = 'red')
plt.title("Videos/Months", color = 'Blue')
plt.grid(True)


plt.plot(x,y1,marker ='o')
plt.plot(x,y2,marker = 'o')
plt.plot([a1,a2],[b1,b2],marker ='o')


plt.show()