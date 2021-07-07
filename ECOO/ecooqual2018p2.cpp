//https://dmoj.ca/problem/ecooqual2018p2
#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;str s,ans;
    cin >> t;
    while (t--) {
        cin >> s;
        ans="";
        for (int i=0;i<s.length();i++) {
            if (s[i]=='E') {
                ans+="Educational ";
            }
            else if (s[i]=='C') {
                ans+="Computing ";
            }
            else if (s[i]=='O') {
                if (s[i+1]=='O') {
                    ans+="Organization of Ontario ";
                }
                i++;
            }
        }
        for (int j=0;j<ans.length();j++) {
            if (j<ans.length()-1) {
                cout << ans[j];
            }
            else {
                cout << endl;
            }
        }
    }
    return 0;
 }

