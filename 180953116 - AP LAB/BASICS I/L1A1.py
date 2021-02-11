n = int(input("Enter value for 'n': "))
m = int(input("Enter value for 'm': "))

while n <= m :

	for i in range(2, n//2) :
		if n%i == 0 :
			break
	else :
		print(n)

	n += 1