#https://dmoj.ca/problem/dpm
N,K=map(int,input().split())
ar=[0]+list(map(int,input().split()))
MOD=(int)(1e9)+7
dp=[[0]*(K+1) for i in range(N+1)]
dp[0][0]=1
for i in range(1,N+1):
    psa=[dp[i-1][0]]
    for j in range(1,K+1): psa.append(psa[-1]+dp[i-1][j])
    for j in range(0,K+1):
        if j<=ar[i]:
            dp[i][j]+=psa[j]
            dp[i][j]%=MOD
        else:
            dp[i][j]+=psa[j]-psa[j-ar[i]-1];
            dp[i][j]%=MOD
print(dp[N][K])

