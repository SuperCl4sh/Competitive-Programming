#include <bits/stdc++.h>
#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
using namespace std;
#define mp make_pair
#define pb push_back
#define pf push_front
#define PF pop_front
#define PB pop_back
#define P push
#define F first
#define S second
#define boost ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define PI 3.14159265
#define len(s) (int)s.length()
#define sz(s) (int)s.size()
#define sp(x) fixed << setprecision(x)
#define all(a) a.begin(),a.end()
typedef long long ll;
typedef string str;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;
typedef pair<double,double>pdd;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ld,ld>pld;
typedef pair<str,str>pss;
typedef pair<char,char>pcc;
typedef pair<long,long>pl;
typedef pair<bool,bool>pbb;
const ll MOD = 1000000007;
const ll high= (ll)(1e15);
const ll MOD2=998244353;
void read(auto &num) {register int Z;num=0;bool negat=0;Z=getchar();if (Z=='-') {negat=1;Z=getchar();}for(;(Z>47&&Z<58);Z=getchar()){num=num*10+Z-48;}if(negat){num*=-1;}}
int n,w;
ll dp[30005][505];
vi ar;
ll total(int l, int r) {
	ll sum=0;
	r=min(r,n-1);
	for (int i=l;i<=r;i++) {
		sum+=ar[i];
	}
	return sum;
}
ll solve(int ind,int balls) {
	if (ind>=n||balls==0) return 0LL;
	else if (dp[ind][balls]!=-1) return dp[ind][balls];
	ll ans=solve(ind+w,balls-1)+total(ind,ind+w-1);
	return dp[ind][balls]=max(ans,solve(ind+1,balls));
}
int main() {
	boost;
	ll k,a,t;
	cin >> t;
	for (int i=0;i<t;i++) {
		cin >> n >> k >> w;
		ar.clear();
		memset(dp,-1LL,sizeof(dp));
		for (int j=1;j<=n;j++) {
			cin >> a;
			ar.pb(a);
		}
		cout << solve(0,k) << "\n";
	}
	return 0;
}