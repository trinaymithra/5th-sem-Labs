f =open("text_file.txt", "r")

fh =f.readlines()

fh =fh[::-1]

for line in fh :
	print (line)

f.close()