//https://dmoj.ca/problem/dwite07c2p2
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;
typedef long double ld;
typedef unsigned long long ull;
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tot=0;str s;
    for (int i=0;i<5;i++) {
        cin >> s;
        for (int f=0;f<s.length();f++) {
            if (s[f]=='-') {
                tot--;
            }
            else if (s[f]=='+') {
                tot++;
            }
            if (tot<0) {
                cout << "OH NOES!" << endl;
                tot=0;
                break;
        }
        if (f==s.length()-1) {
            cout << tot << endl;
        }
        }
    }
    return 0;
 }

