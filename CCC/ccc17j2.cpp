#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;

 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k,tot=0;
    cin >> n >> k;
    for (int i=0;i<=k;i++) {
        tot+=n;
        n*=10;
    }
    cout << tot << endl;
    return 0;
 }