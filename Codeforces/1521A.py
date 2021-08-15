T=int(raw_input())
for _ in range(T):
    A,B=map(int,raw_input().split())
    if B==1: 
        print "NO"
        continue
    W=A
    while W*B<=(int)(1e18): 
        left=A
        right=W*B-A
        if not right%A:
            while right>left and (not left%(A*B) or not right%(A*B)):
                left+=A
                right-=A
            if left<right:
                break
            else: W+=A
        else: W+=A
    print "YES\n",left,right,W*B

