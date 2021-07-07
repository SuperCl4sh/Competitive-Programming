//https://dmoj.ca/problem/nccc3j2
#include <bits/stdc++.h>
using namespace std;
 int main() {
    string s,g,h,v,k;
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> s;
    if (s.length()<=1) {
        cout << "NO" << endl;
         return 0;
    }
    else {
        for (int i=0;i<s.length();i++) {
            g=v;
            g+=s[i];
            h="";
            for (int j=i+1;j<s.length();j++) {
                h+=s[j];
            }
            k=h;
            v=g;
            reverse(h.begin(),h.end());
            reverse(g.begin(),g.end());
            if (h==k && g==v && h.length()>0 && v.length()>0) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
 }

