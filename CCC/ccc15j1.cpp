//https://dmoj.ca/problem/ccc15j1
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;
typedef long double ld;
typedef unsigned long long ull;
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int a,b;
    cin >> a >> b;
    if (a<2||a==2&&b<18) {
        cout << "Before" << endl;
    }
    else if (a==2&&b==18) {
        cout << "Special" << endl;
    }
    else {
        cout << "After" << endl;
    }
    return 0;
 }

