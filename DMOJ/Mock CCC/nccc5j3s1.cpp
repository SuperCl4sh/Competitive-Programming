#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define pf push_front
#define PF pop_front
#define PB pop_back
#define F first
#define S second
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
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,x,tot=0;
    cin >> n >> x;
    int ar[n];
    for (int i=0;i<n;i++) {
        cin >> ar[i];
    }
    sort(ar,ar+n);
    for (int i=0;i<n;i++) {
        for (int j=i+1;j<n;j++) {
            for (int k=j+1;k<n;k++) {
                if (ar[j]==x) tot++;
            }
        }
    }
    cout << tot << endl;
    return 0;
 }