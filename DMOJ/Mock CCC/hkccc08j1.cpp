//https://dmoj.ca/problem/hkccc08j1
#include <iostream>
using namespace std;
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int q,a,b,high=-10000,high2=-10000;
    cin >> q;
    while (q--) {
        cin >> a >> b;
        high=max(high,a*b);
    }
    cin >> q;
    while (q--) {
        cin >> a >> b;
        high2=max(high2,a*b);
    }
    if (high>high2) cout << "Casper" << endl;
    else if (high2>high) cout << "Natalie" << endl;
    else cout << "Tie" << endl;
    return 0;
 }

