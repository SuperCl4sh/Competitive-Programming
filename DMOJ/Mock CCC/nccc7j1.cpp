//https://dmoj.ca/problem/nccc7j1
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
    char c;int tot=0;
    for (int i=0;i<5;i++) {
        cin >> c;
        if (c=='P') tot++;
    }
    cout << tot << endl;
    return 0;
 }

