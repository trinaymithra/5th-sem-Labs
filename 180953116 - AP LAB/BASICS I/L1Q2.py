#QUESTION 2
#DISPLAY THE GIVEN PATTERN

count = 1
for i in range(1,6) :
	for j in range(1,i+1) :
		print(count, end=" ")
		count+=1
	print("")