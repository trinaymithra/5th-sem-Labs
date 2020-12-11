f = open("text_file.txt", "r")
fh = f.readlines()

line_count = 0
word_count = 0
character_count = 0

for line in fh :
    
  line = line.strip()
  words = line.split()
  line_count += 1
  word_count += len(words)
  character_count += len(line)

f.close()

print("Number of lines = ", line_count, "\nNumber of Words = ", word_count, "\nNumber of Characters:", character_count)



