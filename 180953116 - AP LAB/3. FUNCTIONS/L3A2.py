n = int(input('Enter a value for "n": '))

def pascal(n) :
	arr = list()
	d = dict()
	arr.append(1)
	for i in range(n) :
		d[i] = arr
		arr = []
		p = d[i]
		arr.append(1)
		for j in range(1,len(p)) :
			arr.append(p[j-1] + p[j])
		arr.append(1)

	for key in d :
		print(d[key])
pascal(n)