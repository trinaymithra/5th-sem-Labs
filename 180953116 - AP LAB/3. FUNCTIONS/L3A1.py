
def counter(s) :
	l,u = 0,0
	for letter in s :
		if letter.islower() :
			l+=1
		elif letter.isupper() :
			u+=1
	print('Number of lower case letters: ',l)
	print('Number of upper case letters: ',u)

s = input('Enter a string: ')
counter(s)