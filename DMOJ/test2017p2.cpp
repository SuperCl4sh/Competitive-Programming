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
    int a,n,b;
    cin >> n >> b;
    for (int i=0;i<n;i++) {
        cin >> a;
        b-=a;
    }
    if (b<0) {
        cout << "The budget will balance itself" << endl;
    }
    else {
        cout << b << endl;
    }
    return 0;
 }