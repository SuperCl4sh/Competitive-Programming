def good(length):
    for i in range(0,len(A)):
        if i+length>len(A): break
        elif A[i:i+length] in B: return 1
    return 0
T=int(raw_input())
for _ in range(T):
    A=raw_input()
    B=raw_input()
    left=0
    right=min(len(A),len(B))+1
    mid=0
    while right-left>1:
        mid=left+right>>1
        if good(mid): left=mid
        else: right=mid
    print len(A)+len(B)-2*left

