//https://dmoj.ca/problem/vpex1p1
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
    int ar[5],ar2[5];
    for (int i=0;i<5;i++) {
        cin >> ar[i];
    }
    for (int i=0;i<5;i++) {
        cin >> ar2[i];
    }
    sort(ar,ar+5);
    sort(ar2,ar2+5);
    cout << max(ar[4]+ar[3]+ar[2]+ar[1],ar2[4]+ar2[3]+ar2[2]+ar2[1])<<endl;
    return 0;
 }
