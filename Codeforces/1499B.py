T=int(raw_input())
for _ in range(T):
    s=raw_input()
    ind=s.find('11')
    if ind<0:
        print 'YES'
        continue
    ind1=s.find('11')
    if ind1==-1:
        print 'YES'
        continue
    ind2=s.find('00',ind1)
    print 'YES' if ind2==-1 else 'NO'

