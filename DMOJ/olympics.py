import math
N,B,S,G=map(int,input().split())
tot=B+S*3+5*G
if tot>N:
    print(0)
else:
    left=-1
    right=(int)(1e18)
    while right-left>1:
        mid=left+right>>1
        if 5*mid+tot>N: right=mid
        else: left=mid
    print(right)
