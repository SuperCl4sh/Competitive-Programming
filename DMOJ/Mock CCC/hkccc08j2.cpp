//https://dmoj.ca/problem/hkccc08j2
#include <bits/stdc++.h>
using namespace std;
long long g=0;
void solve(string j) {
long long m=0;
string n;
for (int i=0;i<j.length();i++) {
    n=j[i];
    m+=stol(n);
}
g=0LL;
while (m>0) {
    g+=m%10;
    m/=10;
    if (m==0) {
        if (g<10) {
            return;
        }
        m=g;
        g=0;
    }
}
return;
}
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long n;string m;
    cin >> n;
    while (n--) {
        cin >> m;
        solve(m);
        cout << g<<endl;
    }
    return 0;
 }

