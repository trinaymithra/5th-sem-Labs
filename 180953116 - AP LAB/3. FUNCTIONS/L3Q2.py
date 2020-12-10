#QUESTION 2
# define a function to multiply all elements in the list

l = [int(i) for i in input("Enter a list: ").split()]

def unique_ele (a) :
	"return all unique elementsin the given list"
	return list(set(a))

print("List of unique elements in given list: ", unique_ele(l))