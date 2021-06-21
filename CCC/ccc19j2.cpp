//https://dmoj.ca/problem/ccc19j2
#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int a,l;char b;
    cin >> l;
    while (l--) {
        cin >> a >> b;
        for (int i=0;i<a;i++) {
            cout << b;
        }
        cout << endl;
    }
    return 0;

 }
