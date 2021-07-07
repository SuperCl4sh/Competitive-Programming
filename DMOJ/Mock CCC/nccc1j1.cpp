//https://dmoj.ca/problem/nccc1j1
#include <bits/stdc++.h>
using namespace std;
bool hasZero(int n) {
while (n>0) {
    if (n%10==0) return 1;
    n/=10;
}
return 0;
}
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    n++;
    while (hasZero(n)) n++;
    cout << n << endl;
    return 0;
 }

