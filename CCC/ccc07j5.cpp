//https://dmoj.ca/problem/ccc07j5
#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll dp[100];
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    vector<ll>motels={0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
    ll a,b,n,m;
    cin >> a >> b >> n;
    while (n--) {
        cin >> m;
        motels.push_back(m);
    }
    sort(motels.begin(),motels.end());
    dp[0]=1;
    for (ll i=0;i<motels.size();i++) {
        for (ll j=i+1;j<motels.size();j++) {
            if (motels[j]-motels[i]<=b&&motels[j]-motels[i]>=a) {
                dp[j]+=dp[i];
            }


        }
    }
    cout << dp[motels.size()-1] << endl;
    return 0;
 }
