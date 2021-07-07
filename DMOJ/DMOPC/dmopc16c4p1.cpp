//https://dmoj.ca/problem/dmopc16c4p1
#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll ar[70];
void solve (ll a) {
    if (a==1) {
        cout << "T" << endl;
        return;
    }
    if (a%2) {
        cout << "F" << endl;
        return;
    }
    while (a>0) {
        if (a==2 || a==1) {
            cout << "T" << endl;
            return;
        }
        a/=2;
        if (a%2) {
        cout << "F" << endl;
        return;
        }
    }
    cout << "F" << endl;
return;
}
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    ll i;
    while (n--) {
        cin >> i;
        solve(i);
    }
    return 0;
 }

