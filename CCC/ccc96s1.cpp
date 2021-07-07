//https://dmoj.ca/problem/ccc96s1
#include <bits/stdc++.h>
using namespace std;
int tot;
void solve (int a) {
tot=0;
for (int i=1;i<=(int)(sqrt(a));i++) {
    if (a%i==0 && i*i!=a && i!=1) {
        tot+=i+(int)(a/i);
    }
    else if (i*i==a || i==1) {
        tot+=i;
    }
}
if (a==tot) {
    cout << a << " is a perfect number." << endl;
}
else if (a<tot) {
    cout << a << " is an abundant number." << endl;
}
else if (a>tot) {
    cout << a << " is a deficient number." << endl;
}
return;
}
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int a,n;
    cin >> n;
    while (n--) {
        cin >> a;
        solve(a);
    }
    return 0;
 }

