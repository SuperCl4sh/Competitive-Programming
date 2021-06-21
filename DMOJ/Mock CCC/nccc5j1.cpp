#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    cin >> s;
    for (int i=0;i<s.length();i++) {
        if (s[i]=='C' && s[i+1]=='C' && s[i+2]=='C') {
            cout <<"NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
 }