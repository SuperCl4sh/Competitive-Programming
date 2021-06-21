#include <bits/stdc++.h>
using namespace std;

 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int k,cost,h;string s,g,ans,alphabet="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cin >> k;
    cin >> s;
    for (int i=0;i<s.length();i++) {
        cost=3*(i+1)+k;
        h=int(s[i])-cost-65;

        if (h<0) {
            h+=26;
        }
        g=alphabet[h];
        ans+=g;

    }
    cout << ans << endl;

    return 0;
 }