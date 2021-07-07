//https://dmoj.ca/problem/ccc11j5
#include <bits/stdc++.h>
using namespace std;
int n,dp[7]={-1,-1,-1,-1,-1,-1,-1};
int solve(vector <int>ar,int y) {
int ans=1;
if (dp[y]!=-1) {
    return dp[y];
}
for (int i=0;i<n;i++) {
    if (ar[i]==y) {
        ans*=(solve(ar,i+1)+1);
    }
}
dp[y]=ans;
return dp[y];
}
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int a;
    cin >> n;
    vector<int> ar(n);
    for (int i=0;i<n-1;i++) {
        cin >> ar[i];
    }
    cout << solve(ar,n) << endl;
    return 0;
 }

