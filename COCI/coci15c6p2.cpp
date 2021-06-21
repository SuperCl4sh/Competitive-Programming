//https://dmoj.ca/problem/coci15c6p2
#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n,c,curr,ans=0,tot=0;
    cin >> n >> c;
    ll ar[n];
    for (ll i=0;i<n;i++) {
        cin >> ar[i];
    }
    for (ll i=0;i<n;i++) {
        curr=0ll;tot=0ll;
        for (ll j=i;j<n;j++) {
            if (curr+ar[j]>c) continue;
            tot++;
            curr+=ar[j];
        }
        ans=max(ans,tot);
    }
    cout << ans << endl;
    return 0;
 }
