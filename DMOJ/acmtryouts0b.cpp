//https://dmoj.ca/problem/acmtryouts0b
#include <bits/stdc++.h>
using namespace std;
string ans="";
void solve (string a, string b) {
ans="";
for (int i=a.length()-1;i>=0;i--) {
    ans+=b[i];
    ans+=a[i];
}
return;
}
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,n;string a,b;
    cin >> t;
    while (t--) {
        cin >> n >> a >> b;
        solve(a,b);
        cout << ans << endl;
    }
    return 0;
 }

