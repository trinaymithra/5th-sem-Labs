#QUESTION 3
#Operations on dictionaries

import random
import string

print("Enter values of dictionary: (Enter'N' to end)")

inp = input("Enter a value: ")
d= dict()

while inp != 'N' :
	d[random.randrange(1,100)]=inp
	inp = input("Enter a value: ")

count = 0
sm = 0
for ele in d :
	if d[ele].isnumeric() == True :
		sm += int(d[ele])
		count += 1

print("Average = ", sm/count)

result = ""
for ele in d :
	if d[ele].isnumeric() == False :
		result+=d[ele]

print("Concatenated String is: ", result)

search = input("Enter a value to search in the dictionary: ")
key_list = list(d.keys())
value_list = list(d.values())

if search in value_list :
	print("Key is: ", key_list[value_list.index(search)])
else :
	print("Search element not found")

print("Strings that contain only special characters: ")
for value in value_list :
	if all(i in string.punctuation for i in value) :
		print(value) 