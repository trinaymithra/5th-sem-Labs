#QUESTION 1
# define a function to multiply all elements in the list

l = [int(i) for i in input("Enter a list: ").split()]

def mult (a) :
	"Finding the product of elements in the given list"
	product = 1
	for ele in a :
		product *= ele

	return product

print("Multiplication of elements in given list = ", mult(l))