#QUESTION 1
#Store employee details in tuples and search based on ID

class Employee :
	def __init__(self, emp) :
		self.t = tuple(emp)
	def search_id(self, iden) :
		if self.t[0] == iden :
			return "Details are: {}".format(self.t)
		else :
			return False

n = int(input("Enter number of employees: "))

empl = list()
for i in range(n): 
	print("Enter details of " + str(i+1) + "th employee: (id, name, salary, department)")
	emp = input().split()
	empl.append(Employee(emp))

iden = input("Enter I'd of the employee to be searched: ")

for e in empl :
	val = e.search_id(iden)
	if val != False :
		print(val)
		break
else :
	print("No employee found with I'd = ",iden)