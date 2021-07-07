//https://dmoj.ca/problem/rte16j1
#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;int tot=0,cons=0,ans=0;
    getline(cin,s);
    for (int i=0;i<s.length();i++) {
        if (s[i]=='L') {
            tot++;
            cons++;
        }
        else if (s[i]!=' '){
            ans=max(ans,cons);
            cons=0;
        }
    }
    ans=max(ans,cons);
    cout << tot << " " << ans << endl;
    return 0;
 }

