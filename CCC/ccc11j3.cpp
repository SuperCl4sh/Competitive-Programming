//https://dmoj.ca/problem/ccc11j3
#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int a,b,tot=2;
    cin >> a >> b;
    while (true) {
        a^=b;b^=a;a^=b;
        b-=a;
        if (a<0 || b<0) {
            printf("%i\n",tot);
            return 0;
        }
        tot++;
    }
    return 0;
 }

