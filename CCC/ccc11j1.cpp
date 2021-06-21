//https://dmoj.ca/problem/ccc11j1
#include <bits/stdc++.h>
using namespace std;

 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int a,b;
    cin >> a >> b;
    if (a>=3 && b<=4) {
        cout << "TroyMartian" << endl;
    }
    if (a<=6 && b>=2){
        cout << "VladSaturnian" << endl;
    }
    if (a<=2 && b<=3) {
        cout << "GraemeMercurian" << endl;
    }

    return 0;
 }
