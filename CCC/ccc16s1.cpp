#include <bits/stdc++.h>
using namespace std;
string ans="";
void solve (string a,string b) {
int c[26]={0},d[26]={},counter=0;
for (int i=0;i<a.length();i++) {
    c[(int)a[i]-97]++;
}
for (int i=0;i<b.length();++i) {
    if (b[i]=='*') counter++;
    else d[(int)b[i]-97]++;
}
for (int i=0;i<26;i++) {
    if (c[i]<d[i]) {
        ans="N";
        return;
    }
    else if (c[i]>d[i]) {
        counter-=c[i]-d[i];
    }
    if (counter<0) {
        ans="N";
        return;
    }

}
ans="A";
return;

}
 int main() {
     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string a,b;
    cin >> a >> b;
    solve(a,b);
    cout << ans << endl;
    return 0;
 }