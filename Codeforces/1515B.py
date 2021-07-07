T=int(raw_input())
for _ in range(T):
    N=int(raw_input())
    good=0
    left=0
    right=(int)(1e5)
    while right-left>1 and not good:
        mid=left+right>>1
        prod=mid*mid*2
        if prod==N:
            good=1
            break
        elif prod>N: right=mid
        else: left=mid
    else:
        left=0
        right=(int)(1e5)
        while right-left>1:
            mid=left+right>>1
            prod=mid*mid*4
            if prod==N: 
                good=1
                break
            elif prod>N: right=mid
            else: left=mid

    print 'YES' if good else 'NO'
