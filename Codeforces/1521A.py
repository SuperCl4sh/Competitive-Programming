T=int(raw_input())
for _ in range(T):
    A,B=map(int,raw_input().split())
    if B==1 or A==B or not A%B:
        print "NO"
        continue
    W=A
    while W*B<=(int)(1e18):
        left=A
        right=W*B-A
        if not right%A:
            while right>left and (not left%B or not right%B):
                left+=A
                right-=A
            if left<right:
                break
            else: W+=A
        else: W+=A

        
    else:
        assert 0
    assert left%B!=0!=right%B
    print "YES\n",left,right,W*B


