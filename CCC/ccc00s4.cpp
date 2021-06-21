#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define pf push_front
#define PF pop_front
#define PB pop_back
#define P push
#define F first
#define S second
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define MOD 1e9+7
typedef long long ll;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;
typedef pair<double,double>pdd;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ld,ld>pld;
typedef pair<str,str>pss;
char _;
ll dp[5500];
 int main() {
    boost;
    ll d,n;
    cin >> d >> n;
    ll clubs[n];
    for (int i=0;i<n;i++) {
        cin >> clubs[i];
    }

    for (int i=0;i<sizeof(dp)/sizeof(dp[0]);i++) {
        dp[i]=INT_MAX;
    }
    dp[0]=0;
    for (ll i=0;i<d;i++) {
        for (ll j=0;j<n;j++) {
            if (i+clubs[j]<=d) {
                dp[i+clubs[j]]=min(dp[i]+1,dp[i+clubs[j]]);
            }
        }
    }
    if (dp[d]!=INT_MAX) {
    printf("Roberta wins in %i strokes.\n",dp[d]);
    }
    else {
        printf("Roberta acknowledges defeat.\n");
    }
    return 0;
 }