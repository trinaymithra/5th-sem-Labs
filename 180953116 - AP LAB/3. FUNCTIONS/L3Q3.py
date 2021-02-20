def fun() :
	a = 5
	b = 6
	c = a+b
	print(c)

print(fun.__code__.co_nlocals)