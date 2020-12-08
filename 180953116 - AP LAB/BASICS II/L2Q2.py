#QUESTION 2
#Operation on matrices using dictionaries

ar, ac = input("Enter order of first matrix: ").split()
br, bc = input("Enter order of second matrix: ").split()

if ar == br and ac == bc :

	ad = dict()
	bd = dict()

	result = list()

	print("Input matrix A: ")
	for i in range(int(ar)) :
		r =[int(j) for j in input("Enter a row: ").split()]

		for ele in r :
			if ele == 0 :
				pass
			else :
				ad[str(int(i)) + str(r.index(ele))] = int(ele)

	print("Input matrix B: ")
	for i in range(int(br)) :
		r =[int(j) for j in input("Enter a row: ").split()]

		for ele in r :
			if ele == 0 :
				pass
			else :
				bd[str(int(i)) + str(r.index(ele))] = int(ele)

	for i in range(int(ar)) :
		row = list()
		for j in range(int(ac)) :
			ind = str(int(i)) + str(int(j))
			if ind in ad and ind in bd :
				row.append(int(ad[ind]) + int(bd[ind]))
			elif ind in ad and ind not in bd :
				row.append(int(ad[ind]))
			elif ind not in ad and ind in bd :
				row.append(int(bd[ind]))
			elif ind not in ad and ind not in bd :
				row.append(int('0'))

		result.append(row)

	print("Addition of given two matrices: ")
	for ro in result :
		for ele in ro :
			print(ele, end = " ")
		print("")

else :
	print("Orders do not match to add the matrices")