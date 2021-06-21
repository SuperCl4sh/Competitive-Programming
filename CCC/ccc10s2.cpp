//https://dmoj.ca/problem/ccc10s2
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
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
    int n,ind;str a,b,s,ans,curr="",g;
    cin >> n;
    vector<pss>ar;
    for (int i=0;i<n;i++) {
        cin >> a >> b;
        ar.pb(mp(a,b));
    }
    cin >> s;
    ans="";
    for (int i=0;i<s.length();i++) {
        g=s[i];curr+=g;
        for (int e=n-1;e>=0;e--) {
            if (curr==ar[e].S) {
                ans+=ar[e].F;
                curr="";
                break;

            }

        }
    }
    cout << ans << endl;
    return 0;
 }
