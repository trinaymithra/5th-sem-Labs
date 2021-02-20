def a() :
	print('In function "a"')
	def b() :
		print('In function "b" which is inside function "a"')
	b()

a()