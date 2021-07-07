//https://dmoj.ca/problem/16bitswonly
#include <bits/stdc++.h>
using namespace std;
string ans="";
void solve (long long a, long long b, long long p) {
if (a*b==p) {
    ans="POSSIBLE DOUBLE SIGMA";
}
else {
    ans="16 BIT S/W ONLY";
}
return;
}
int main() {
ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int n;long long a,b,p;
cin >> n;
while (n--) {
    cin >> a >> b >> p;
    solve(a,b,p);
    cout << ans << endl;
}
return 0;
}

