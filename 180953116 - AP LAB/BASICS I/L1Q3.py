#QUESTION3
#OPERATIONS ON STRINGS

n = int(input("Enter a number 'n': "))

s_list = list()
for i in range(n) :
	s_list.append(input("Enter the string: "))

count = 0
for s in s_list :
	if s[0]==s[-1] and len(s) > 1 :
		count+=1

print("Count of strings that start and end with same character and have more than 2 characters is: ", count)


print("Strings that have odd length are: ")
for s in s_list :
	if len(s) %2 == 1 :
		print(s)