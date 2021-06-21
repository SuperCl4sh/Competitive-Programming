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
ll P_Pow[200001],p_pow[200001],prime=131;int n;str s;
void construct() {
	P_Pow[200000]=prime,p_pow[200000]=prime;
	for (int i=199999;i>=0;i--) {
		P_Pow[i]=(P_Pow[i+1]*prime)%MOD;
		p_pow[i]=(p_pow[i+1]*prime)%MOD2;
	}
	return;
}
bool exist(int a) {
	ll hash=0,hash2=0;
	for (int i=0;i<a;i++) {
		hash=(hash+((P_Pow[i]*ll(s[i]))%MOD))%MOD;
		hash2=(hash2+((p_pow[i]*ll(s[i]))%MOD2))%MOD2;
		
	}
	vector<pll>ar;
	ar.pb(mp(hash,hash2));
	for (int i=1;i+a-1<n;i++) {
		hash=hash-((s[i-1]*P_Pow[0])%MOD);
		hash=(hash+MOD)%MOD;
		hash=(hash+((s[i+a-1]*P_Pow[a])%MOD))%MOD;
		hash=(hash*prime)%MOD;
		hash2=hash2-((s[i-1]*p_pow[0])%MOD2);
		hash2=(hash2+MOD2)%MOD2;
		hash2=(hash2+((s[i+a-1]*p_pow[a])%MOD2))%MOD2;
		hash2=(hash2*prime)%MOD2;
		ar.pb(mp(hash,hash2));
	}
	sort(all(ar));
	for (int i=0;i<sz(ar)-1;i++) {
		if (ar[i].F==ar[i+1].F&&ar[i].S==ar[i+1].S) return 1;
	}
	return 0;
}
int main() {
	boost;
	cin >> n;
	cin >> s;
	construct();
	ll left=0,right=n,mid;
	while (right-left>1) {
		mid=(left+right)/2;
		if (exist(mid)) left=mid;
		else right=mid;
	}
	cout << left << "\n";
	return 0;
}