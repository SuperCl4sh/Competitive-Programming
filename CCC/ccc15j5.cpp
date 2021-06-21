#include <bits/stdc++.h>
using namespace std;
int dp[300][300][300];
int solve (int pie, int rem, int prev) {
if (dp[pie][rem][prev]==0) {
    if (rem==1 || pie==0 && rem==0) {
        dp[pie][rem][prev]=1;
        return dp[pie][rem][prev];
    }
    int tot=0;
    if (rem==0) {
        return 0;
    }
    for (int i=prev;i<=(int)(pie/rem);i++) {
        tot+=solve(pie-i,rem-1,i);
    }
    dp[pie][rem][prev]=tot;
}
return dp[pie][rem][prev];


}
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k;
    cin >> n >> k;
    cout << solve(n,k,1) << endl;
    return 0;
 }