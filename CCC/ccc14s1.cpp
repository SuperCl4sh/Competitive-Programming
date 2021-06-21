#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;


 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll t,k,n,j=0;
    cin >> k;
    vector<ll>ar;
    for (ll i=1;i<=k;i++) {
        ar.push_back(i);
    }
    cin >> t;
    while (t--) {
        cin >> n;

        j=1;
        if (n<=ar.size()) {
        for (ll p=0;p<ar.size();p++) {
            if (n==j) {
                ar[p]=-1;
                j=1;
            }
            else {
                j++;
            }
        }
        }
        for (ll a=ar.size()-1;a>=0;a--) {
            if (ar[a]==-1) {
                ar.erase(ar.begin()+a);
            }
        }
    }

    for (ll x=0;x<ar.size();x++) {
        cout << ar[x] << endl;
    }


    return 0;
 }