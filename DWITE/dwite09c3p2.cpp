//https://dmoj.ca/problem/dwite09c3p2
#include <bits/stdc++.h>
using namespace std;
long long  b,c;
void solve (long long n) {
b=0,c=1;
while (true) {
    if (c>=n) {
        break;
    }
    b^=c;c^=b;b^=c;c+=b;


}
if (n-b<abs(n-c)) {
    cout << b << endl;
}
else if (n-b>abs(n-c)) {
    cout << c << endl;
}
else {
    cout << c << endl;
}
return;

}
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long a;
    for (int i=0;i<5;i++) {
        cin >> a;
        solve(a);
    }
    return 0;
 }
