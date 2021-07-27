#https://dmoj.ca/cpc21c1p3
import sys
input=sys.stdin.readline
T=int(input())
for _ in range(T):
    R1,R2,R3=map(int,input().split())
    ans=0
    if -R2+R3<-R1-R3:
        ans+=pow(-R2+R3,2)-pow(-R1-R3,2)
    if R1>R3:
        ans+=pow(R1-R3,2)
    if R3>R1:
        ans+=pow(min(R2-R3,-R1+R3),2)
    tot=pow(R2-R3,2)
    final_ans=ans/tot
    print(final_ans)
