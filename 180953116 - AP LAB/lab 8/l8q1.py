import re

fun_list = dir(re)
#print(fun_list)
res = list()

for fun in fun_list :
	#print(fun)
	if re.search("find", fun) :
		res.append(fun)

print(res)