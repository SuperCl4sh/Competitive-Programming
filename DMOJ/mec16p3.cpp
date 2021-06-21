/*
ID: 
TASK:  
LANG: C++                 
*/

#include <bits/stdc++.h>

#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
using namespace std;
//ofstream fout (".out");
//ifstream fin (".in");
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
#define mem(ar,a) memset(ar,a,sizeof(ar))
#define MT make_tuple
typedef long long ll;
typedef string str;
typedef vector<ll>vll;
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
const ll MOD=998244353LL;
const ll high= (ll)(1e15);
const ll MOD2 = 1000000007LL;
void read(auto &num) {register int Z;num=0;bool negat=0;Z=getchar();if (Z=='-') {negat=1;Z=getchar();}for(;(Z>47&&Z<58);Z=getchar()){num=num*10+Z-48;}if(negat){num*=-1;}}
void Read(auto &num) {register int Z;num=0;bool negat=0;Z=getchar_unlocked();if (Z=='-') {negat=1;Z=getchar_unlocked();}for(;(Z>47&&Z<58);Z=getchar_unlocked()){num=num*10+Z-48;}if(negat){num*=-1;}}
ll modmul(ll a, ll b, ll m) {ll ans=a*b-m*ll(1.L/m*a*b);return ans+m*(ans<0)-m*(ans>=m);}
ll Pow(ll a, ll b, ll mod) {ll ans=1;for (; b;a=modmul(a,a,mod),b/=2) {if (b&1) ans=modmul(ans,a,mod);}return ans;}
void Print(auto &temp) {for (auto x: temp) cout << x << " ";cout << "\n";return;}
int n,t;
vector<vector<pii>>ar;
int dp[101][101][101];
int solve(int ind, int ind2,int time) {
	if (time>t) return INT_MIN;
	else if (sz(ar[ind])<ind2) return 0;
	else if (sz(ar)==ind) return 0;
	else if (dp[ind][ind2][time]!=-1LL) return dp[ind][ind2][time];
	int ret=0;
	ret=solve(ind+1,0,time);
	ret=max(solve(ind+1,0,time+ar[ind][ind2].F)+ar[ind][ind2].S,ret);
	ret=max(ret,solve(ind,ind2+1,time+ar[ind][ind2].F)+ar[ind][ind2].S);
	return dp[ind][ind2][time]=ret;	
}
int main() {
	boost;
	int l,x,a;
	mem(dp,-1);
	cin >> n >> t;
	for (int i=0;i<n;i++) {
		vector<pii>curr;
		cin >> l;
		for (int j=0;j<l;j++) {
			cin >> x >> a;
			curr.pb(mp(x,a));
		}
		ar.pb(curr);
		curr.clear();
	}
	cout << solve(0,0,0) << "\n";




	return 0;
}