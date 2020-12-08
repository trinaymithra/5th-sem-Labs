#QUESTION 1
#Count number of words in a sentence using dictionaries

s = input("Enter a string: ")
s_list = list(s.split())

d = dict()

for item in s_list :
	if item in d.keys() :
		d[item]+=1
	else :
		d[item]=1

count = 0
for pair in d :
	count+=d[pair]

print("Number of words = ",count)