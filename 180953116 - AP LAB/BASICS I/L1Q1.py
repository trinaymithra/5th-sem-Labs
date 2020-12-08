#QUESTION 1
#odd from first and even from second list

first = list(input("Enter first list: ").split())
second = list(input("Enter second list: ").split())

result = list()

for i in first :
	if int(i) % 2 == 1 :
		result.append(i)

for i in second :
	if int(i) % 2 == 0 :
		result.append(i)

print(result)