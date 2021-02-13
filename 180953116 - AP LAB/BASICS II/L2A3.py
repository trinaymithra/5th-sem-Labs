#create a text file with name text1.txt in the same directory

fh = open('text1.txt')

store_data = dict()
freq = dict()
i = 1
for line in fh :
	value = list()
	value.append(line.strip())
	value.append(len(line))
	store_data[i] = value
	i+=1

	for letter in line :
		if letter not in freq.keys() :
			freq[letter] = 1
		else :
			freq[letter] += 1

print(store_data)
print(freq)

fh.close()