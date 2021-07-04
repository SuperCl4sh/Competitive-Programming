K=int(raw_input())
for _ in range(K):
    N,X,T=map(int,raw_input().split())
    if X>T or N==1:
        print 0
        continue
    val=T//X-1
    total_one=(val*(val+1))/2
    pos=N-T//X
    if pos<0: #total is sum of numbers from 1 to N-1 (N*(N-1))/2
        pos=0
        total_one=N*(N-1)/2
    print total_one+pos*(T//X)


