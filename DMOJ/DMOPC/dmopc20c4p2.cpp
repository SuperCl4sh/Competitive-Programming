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


int main() {
	boost;
	ll a,b,n,m,k;
	cin >> n >> m >> k;
	map<ll,int>rows,cols;
	for (int i=0;i<k;i++) {
		cin >> a >> b;
		if (cols[b]==1) cols[b]=0;
		else cols[b]=1;
		if (rows[a]==1) rows[a]=0;
		else rows[a]=1;
		if (rows[a]==0) rows.erase(a);
		if (cols[b]==0) cols.erase(b);
	}
	vector<pll>ans;
	map<ll,int>::iterator it,it2;
	if (sz(cols)==sz(rows)) {
		for (it=rows.begin(),it2=cols.begin();it!=rows.end()&&it2!=cols.end();++it,++it2) {
			ans.pb(mp(it->F,it2->F));
		}
	}
	else {
		for (it=rows.begin(),it2=cols.begin();it!=rows.end()&&it2!=cols.end();++it,++it2) {
			ans.pb(mp(it->F,it2->F));
		}
		if (sz(cols)>sz(rows)) {
			for (;it2!=cols.end();++it2) {
				ans.pb(mp(1LL,it2->F));
			}
			
		}
		else {
			for (;it!=rows.end();++it) {
				ans.pb(mp(it->F,1LL));
			}
		}
	}
	cout << sz(ans) << "\n";
	for (int i=0;i<sz(ans);i++) {
		cout << ans[i].F << " " << ans[i].S << "\n";
	}
	
	
	return 0;
}