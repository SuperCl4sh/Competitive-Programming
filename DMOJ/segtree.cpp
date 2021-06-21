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
#define FOR(i,n) for (int i=0;i<n;i++) 
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
ll ar[100005],tree[100005];int n,m;

void construct() {
	for (int i=n-1;i>=0;i--) {
		tree[i+n]=ar[i];
	}
	for (int i=n-1;i>=0;i--) {
		tree[i]=min(tree[i*2],tree[i*2+1]);
	}
	return;
}
void update(ll ind, ll val) {
	tree[ind]=val;
	ll New;
	while (ind>1) {
		ind/=2;
		New=min(tree[2*ind],tree[2*ind+1]);
		if (tree[ind]==New) {
			return;
		}
		tree[ind]=New;
	}
	return;
}
void calc(ll a, ll b) {
	ll ret=high;
	while (a<b) {
		if (a&1) ret=min(ret,tree[a]),++a;
		if (b&1) {
			b--;ret=min(ret,tree[b]);
		}
		a/=2,b/=2;
	}
	cout << ret << "\n";
}

int main() {
	boost;
	ll a,b;
	cin >> n >> m;
	FOR (i,n) {
		cin >> ar[i];
	}
	construct();
	char c;
	while (m--) {
		cin >> c;
		if (c=='M') {
			cin >> a >> b;
			update(a+n,b);
		}
		else {
			cin >> a >> b;
			calc(a+n,b+n+1);
		
		}
	}
	
	return 0;
}