//https://dmoj.ca/problem/ecoo17r3p1
#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;


 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int a,f,d,tot=0,soldDay;
    for (int i=0;i<10;i++) {
        cin >> f >> d;
        tot=0;
        vector<int>ar(f);
        for (int w=0;w<d;w++) {
            soldDay=0;
            for (int g=0;g<f;g++) {
                cin >> a;
                ar[g]+=a;
                soldDay+=a;
            }
            if (soldDay%13==0) {
                tot+=soldDay/13;
            }
        }
        for (int e=0;e<f;e++) {
            if (ar[e]%13==0) {
                tot+=ar[e]/13;
            }
        }
        cout << tot << endl;
    }

    return 0;
 }
