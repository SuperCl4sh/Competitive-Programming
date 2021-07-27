#https://dmoj.ca/cpc21c1p1
T=int(raw_input())
stop=(int)(1e2)
for _ in xrange(T):
    A,B=map(int,raw_input().split())
    ans=0
    good=1
    while A:
        A*=10
        change=int(A/B)
        A-=change*B
        if ans>stop:
            good=0
            break
        ans+=1
    print -1 if not good else ans
