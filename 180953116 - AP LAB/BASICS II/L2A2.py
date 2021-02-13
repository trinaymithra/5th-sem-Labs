s1 = list(input("Enter 1st list: ").split())
s2 = list(input("Enter 2nd list: ").split())

union = list()
inter = list()
diff = list()

for ele in s1 :
	union.append(ele)
for ele in s2 :
	if ele not in union :
		union.append(ele)

for ele in s1 :
	if ele in s2 :
		inter.append(ele)

for ele in s1 :
	if ele not in s2 :
		diff.append(ele)

print("Union: ", union)
print("Intersection: ", inter)
print("Difference: ", diff)