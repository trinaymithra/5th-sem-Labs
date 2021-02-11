n = int(input("Enter a number: "))

ns = str(n)
nl = len(ns)

nc = n

s = 0
while n > 0 :
	po = n % 10
	s+=(po**nl)
	n = n//10

if s == nc :
	print(ns + " is an armstrong number")
else :
	print(ns + " is not an armstrong number")