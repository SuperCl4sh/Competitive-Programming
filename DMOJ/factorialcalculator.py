N=int(input())
curr=1
exponent=0
for i in range(1,N+1):
    curr*=i
    while curr>10:
        curr/=10
        exponent+=1
print('{:.9f}e+{}'.format(curr,exponent))
