f = open("text_file.txt", "r")
fh = f.readlines()

d =dict()

for line in fh :
	line = line.strip()
	words = line.split()
	for word in words :
		d[word] = d.get(word,0) + 1

f.close()

for key in d.keys() :
	print("{} occured {} times in the file".format(key, d[key]))
