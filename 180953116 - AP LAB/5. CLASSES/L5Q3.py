# QUESTION 3
# Get all unique subsets using class

class subset_listing :
	def __init__(self, num_list) :
		self.num_list = num_list

	def print_subsets(self) :
		subset_list = list()
		append_zeroes = "0"
		len_list = len(self.num_list)

		for i in range(2**len_list) :
			bin_i = str(bin(i))[2:]
			bin_i = append_zeroes*(len_list - len(bin_i)) + bin_i
			subset = {self.num_list[j] for j, bit in enumerate(bin_i) if bit == '1'}
			subset_list.append(subset)

		for ele in subset_list :
			print (ele)


l = [int(i) for i in input("Enter a list of integers: ").split()]
l = list(set(l))
obj = subset_listing(l)
obj.print_subsets()