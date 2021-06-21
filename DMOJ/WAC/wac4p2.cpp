//https://dmoj.ca/problem/wac4p2
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
using namespace std;

#define mp make_pair
#define pb push_back
#define pf push_front
#define PF pop_front
#define PB pop_back
#define P push
#define F first
#define S second
#define scann(speed){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}speed=s*f;}
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define make_tuple MT
#define PI 3.14159265
#define len(s) (int)s.length()
#define sz(s) (int)s.size()
#define sp(x) fixed << setprecision(x)
typedef long long ll;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;
typedef pair<double,double>pdd;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ld,ld>pld;
typedef pair<str,str>pss;
typedef pair<long,long>pl;
char _;
const int MOD = 1000000007;
const ll mxN= (ll)(1e15);
vector<pll>ar(1);
ll required=0,dp[5001][5001];
ll solve(ll ind, ll points) {
if (ind==0) {
	if (points>=required) return 0;
	return mxN;
}
else if (dp[ind][points]!=-1) return dp[ind][points];
return dp[ind][points]=min(solve(ind-1,points),solve(ind-1,points+ar[ind].S)+ar[ind].F/2+1);
}
int main() {
    boost;
    memset(dp,-1,sizeof(dp));
    ll a,b,n,tot=0;
    cin >> n;
    
    for (int i=0;i<n;i++) {
    	cin >> a >> b;
	ar.pb(mp(a,b));
	required+=b;tot+=b;
    }
    required/=2;
    required++;
    cout << solve(n,0) << "\n";
    return 0;

}
