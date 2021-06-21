#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;

 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int x,y;
    cin >> x >> y;
    if (x>0&&y>0) {
        cout << 1 << endl;
    }
    else if (x>0&&y<0) {
        cout << 4 << endl;
    }
    else if (x<0&&y>0) {
        cout << 2 << endl;
    }
    else {
        cout << 3 << endl;
    }
    return 0;
 }