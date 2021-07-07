/*
ID: 
TASK: fence
LANG: C++                 
*/
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
#define boost ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define PI 3.14159265
#define len(s) (int)s.length()
#define sz(s) (int)s.size()
#define sp(x) fixed << setprecision(x)
#define all(a) a.begin(),a.end()
#define mem(ar,a) memset(ar,a,sizeof(ar))
#define MT make_tuple
#define FOR(i,a,n) for (int i=a;i<n;i++)
#define vt vector
typedef long long ll;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;
typedef pair<long double, long double>pld;
typedef pair<double,double>pdd;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ld,ld>pld;
typedef pair<str,str>pss;
typedef pair<char,char>pcc;
typedef pair<long,long>pl;
typedef pair<bool,bool>pbb;
const ll MOD = 1000000007LL;
const ll MOD2=998244353LL;
const ll high= (ll)(1e15);
const int INF=0x3f3f3f;
void read(auto &num) {register int Z;num=0;bool negat=0;Z=getchar();if (Z=='-') {negat=1;Z=getchar();}for(;(Z>47&&Z<58);Z=getchar()){num=num*10+Z-48;}if(negat){num*=-1;}}
void Read(auto &num) {register int Z;num=0;bool negat=0;Z=getchar_unlocked();if (Z=='-') {negat=1;Z=getchar_unlocked();}for(;(Z>47&&Z<58);Z=getchar_unlocked()){num=num*10+Z-48;}if(negat){num*=-1;}}
ll modmul(ll a, ll b, ll m) {ll ans=a*b-m*ll(1.L/m*a*b);return ans+m*(ans<0)-m*(ans>=m);}
ll Pow(ll a, ll b, ll mod) {ll ans=1;for (; b;a=modmul(a,a,mod),b/=2) {if (b&1) ans=modmul(ans,a,mod);}return ans;}
ll Pow(ll a, ll b) {ll ret=1;while (b) {if (b&1) ret*=a;a*=a;b>>=1;}return ret;}
/*--------------------------------------------------------------PROGRAM START-------------------------------------------------------------------------*/
vt<vt<int>>adj(505);
vt<int>res;
void solve(int node) {
	FOR (i,0,sz(adj[node])) {
		int go=adj[node][i];
		FOR (j,0,sz(adj[go])) {
			if (adj[go][j]==node) {
				adj[go].erase(adj[go].begin()+j);
				break;
			}
		}
		adj[node].erase(adj[node].begin()+i);
		i=-1;
		solve(go);
	}
	res.pb(node);
	return;
}
int main() {
	boost;
	freopen("fence.in","r",stdin);
	freopen("fence.out","w",stdout);
	int a,b,f;
	cin >> f;
	int start=1;
	FOR (i,0,f) {
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	FOR (i,1,sz(adj)) {
		sort(all(adj[i]));
	}
	FOR (i,1,sz(adj)) {
		if (sz(adj[i])&1) {start=i;break;}
	}
	solve(start);
	reverse(all(res));
	FOR (i,0,sz(res)) cout << res[i] << "\n";
	
	return 0;
}

