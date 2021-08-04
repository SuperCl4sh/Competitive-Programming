import math
N=int(raw_input())
X=N//2
print (math.factorial(N)/(math.factorial(X)*math.factorial(N-X))*(math.factorial(X-1))**2)/2
