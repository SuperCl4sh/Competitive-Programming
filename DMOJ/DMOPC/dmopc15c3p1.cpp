//https://dmoj.ca/problem/dmopc15c3p1
#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    for (int i=a;i<b;i++) {
        if (i>=c&&i<d) {
            cout << "YES" << endl;
            return 0;
        }
    }
    for (int i=c;i<d;i++) {
    if (i>=a&&i<b) {
        cout << "YES" << endl;
        return 0;
    }
    }
    cout << "NO" << endl;
    return 0;
 }
