//https://dmoj.ca/problem/dmopc15c3p4
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
    ll x,y,hour;int n;
    cin >> n;
    vector<pll>ar;
    for (int i=0;i<n;i++) {
	    cin >> x >> y;
	    ar.pb(mp(x,y));
    }
    int src,q;
    cin >> src >> q;
    src--;
    ll dist[n];
    mem(dist,0x3f3f3f);
    dist[src]=0;
    int start=-1;
    bool seen[n];
    mem(seen,0);
    for (int _=0;_<n-1;_++) {
	    for (int j=0;j<n;j++) {
	    	if (!seen[j]&&((start==-1)||dist[j]<dist[start])) start=j;
	    }
	    seen[start]=1;
	    for (int i=0;i<n;i++) {
	    	if (i==start) continue;
		ll calc=dist[start]+(ar[i].F-ar[start].F)*(ar[i].F-ar[start].F)+(ar[i].S-ar[start].S)*(ar[i].S-ar[start].S);
		if (calc<dist[i]) {
			dist[i]=calc;
		}
	    }
	    start=-1;
    }
    sort(dist,dist+n);
    while (q--) {
    	cin >> hour;
	cout << upper_bound(dist,dist+n,hour)-dist << "\n";
    }
    
    
    
    return 0;
}

