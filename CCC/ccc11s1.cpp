//https://dmoj.ca/problem/ccc11s1
#include <bits/stdc++.h>
using namespace std;
string ans="";
void solve (vector <string> sa) {
int t=0,T=0,s=0,S=0;
for (int i=0;i<sa.size();i++) {
    for (int j=0;j<sa[i].size();j++) {
        if (sa[i][j]=='T') {
            T++;
        }
        else if (sa[i][j]=='t') {
            t++;
        }
        else if (sa[i][j]=='s') {
            s++;
        }
        else if (sa[i][j]=='S') {
            S++;
        }
    }
}
if (t+T>S+s) {
    ans="English";
}
else {
    ans="French";
}
return;
}
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s,g;
    vector <string> a;
    getline(cin,s);
    for (int i=0;i<stoi(s);i++) {
        getline(cin,g);
        a.push_back(g);
    }
    solve(a);
    cout << ans << endl;
    return 0;
 }
