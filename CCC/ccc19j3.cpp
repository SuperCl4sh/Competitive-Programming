//https://dmoj.ca/problem/ccc19j3
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;
typedef long double ld;
typedef unsigned long long ull;
char curr;int tot;
void solve(string s) {
char curr=s[0];
tot=1;
for (int i=1;i<s.length();i++) {
    if (s[i]==curr) {
        tot++;
    }
    else {
        cout << tot << " " << curr << " ";
        curr=s[i];
        tot=1;
    }
}
if (tot>0) {
    cout << tot << " " << curr << endl;
}




return;
}
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;str s;
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> s;
        solve(s);
    }

    return 0;
 }
