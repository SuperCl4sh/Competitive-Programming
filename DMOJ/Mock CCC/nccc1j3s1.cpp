//https://dmoj.ca/problem/nccc1j3s1
#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    double k,p,x,m=1,tot,ans=INT_MAX;
    cin >> k >> p >> x;
    while (true) {
        tot=m*x+(k*p)/m;
        if (tot>ans) {
            cout << fixed << setprecision(3) << ans << endl;
            return 0;
        }
        ans=tot;
        m++;
    }
    return 0;
 }

