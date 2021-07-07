//https://dmoj.ca/problem/nccc6j3
#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a,b,c;string ans="NO";
void solve (int tot) {
if (ans=="YES") {
    return;
}
if (tot>c) {
    return;
}
if (tot==c) {
    ans="YES";
}
solve(tot+a);
solve(tot+b);
return;
}
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
       cin >> a >> b>>c;
       ans="NO";
       solve(0);
       cout << ans << endl;
    }
    return 0;
 }

