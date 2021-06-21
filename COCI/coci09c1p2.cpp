//https://dmoj.ca/problem/coci09c1p2
#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int a,tot=0;
    cin >> a;
    for (int i=0;i<=a;i++) {
        for (int j=i;j<=a;j++) {
            tot+=i+j;
        }
    }
    cout << tot << endl;
    return 0;
 }
