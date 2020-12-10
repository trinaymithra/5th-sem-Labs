#QUESTION 2
#Using built-in modules to find sin, sqrt and log values of given complex number

import cmath

n = complex(input("Enter a complex number(Format: x+yj): "))

print("Sine of ",n," is ", cmath.sin(n))
print("Sqrt of ",n," is ", cmath.sqrt(n))
print("Log of ",n," to the base 'e' is ", cmath.log(n))