#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main () {
    int w;int l;int square; int ans;
    cin >> w >> l;
    cin >> square;
    if (l<square || w < square) {
        cout << 0 << endl;
        return 0;
    }
    else {
        ans = (l/square)*(w/square);
    }
    cout << ans << endl;
    return 0;

}