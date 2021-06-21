//https://dmoj.ca/problem/cchange
#include <bits/stdc++.h>
int dp[10010];
using namespace std;
vector<int> ar;
int solve (int x) {
    if (x==0) {
        return 0;
    }
    if (x<0) {
        return -1;
    }
    else if (dp[x]!=INT_MAX) {
        return dp[x];
    }
    int a = INT_MAX;
    for (int i=0;i<ar.size();i++) {
        int b = solve(x-ar[i]);
        if (b>=0 && b<a) {
            a=b+1;
        }
    }
    dp[x]=a;
    return dp[x];


}
int main() {
ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int a,x,n;
for (int i=0;i<sizeof(dp)/sizeof(dp[0]);i++) {
    dp[i]=INT_MAX;
}
cin >> x >> n;
for (int i=0;i<n;i++) {
    cin >> a;
    ar.push_back(a);
}
cout << solve(x) << endl;
return 0;
}
