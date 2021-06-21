#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
string s;
void solve () {
int index=1;
for (int i=0;i<s.length();i++) {
    if (s[i]=='A') {
        if (index==1) {
            index=2;
        }
        else if (index==2) {
            index=1;
        }
    }
    else if (s[i]=='B') {
        if (index==2) {
            index=3;
        }
        else if (index==3) {
            index=2;
        }
    }
    else {
        if (index==1) {
            index=3;
        }
        else if (index==3) {
            index=1;
        }
    }
}
cout << index << endl;


return;
}
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> s;
    solve();
    return 0;
 }