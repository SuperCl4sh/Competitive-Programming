#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define pf push_front
#define PF pop_front
#define PB pop_back
#define F first
#define S second
#define boost ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;
typedef pair<double,double>pdd;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ld,ld>pld;
typedef pair<str,str>pss;

 int main() {
    boost;
    int n,tot=10;
    cin >> n;
    int ar[n];
    for (int i=0;i<n;i++) {
        cin >> ar[i];
        tot+=ar[i];
    }
    sort(ar,ar+n,greater<int>());
    cout << tot+ar[0]+ar[1] << endl;

    return 0;
 }