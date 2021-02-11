clst = 'abcdefABCDEF0123456789'

s = input("Enter a string to check if it is a hexadecimal number: ")

for digit in s :
	if digit not in clst :
		print(s + " is not a hexadecimal number")
		break
else :
	print(s + " is a hexadecimal number")