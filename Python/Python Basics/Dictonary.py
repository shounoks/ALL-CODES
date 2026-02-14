#When you have a huge data .
# And you want use data in an afficant way or fast way or a fast way with every values.
# Where you can assing a key.
# Normally in a list you will use the index number .
# But in Dictionary we will assing a key.
# Key should be unique.
# Here we will use {} beacuse it's also a type of set and set's are unchangeable or unique.

# Dictionary creation
d = {'navin': 'Samsung', 'rahul': 'Iphone', 'Shounok': 'Redmi'}

# Access all keys
print("Keys:", d.keys())

# Access all values
print("Values:", d.values())

# Access specific value using key
print("Value for 'rahul':", d['rahul'])

# Access specific value using get() method
print("Value for 'Shounok':", d.get('Shounok'))


#Names_color = {'Shounok': 'Shiv','Parama': 'Kali','Chandra':'Chandrashekhar'}
#print(Names_color)
#print("Key is : ",Names_color.keys())
#print("Values : ",Names_color.values())
#print(Names_color.get('Parama'))
#print(Names_color['Chandra'])



