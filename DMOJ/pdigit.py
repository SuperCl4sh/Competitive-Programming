from math import gcd
T=int(input())
for _ in range(T):
    N,K=map(int,input().split())
    target=(N%K)%gcd(pow(10,len(str(N))),K)
    curr=pow(10,len(str(N)))%gcd(pow(10,len(str(N))),K)
    print('YES' if curr==target else 'NO')
