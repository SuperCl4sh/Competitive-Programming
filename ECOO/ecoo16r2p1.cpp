//https://dmoj.ca/problem/ecoo16r2p1
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
typedef long long ll;
typedef string str;
typedef vector<ll>vll;
typedef vector<int> vi;
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
void read(auto &num) {register int Z;num=0;bool negat=0;Z=getchar();if (Z=='-') {negat=1;Z=getchar();}for(;(Z>47&&Z<58);Z=getchar()){num=num*10+Z-48;}if(negat){num*=-1;}}
void Read(auto &num) {register int Z;num=0;bool negat=0;Z=getchar_unlocked();if (Z=='-') {negat=1;Z=getchar_unlocked();}for(;(Z>47&&Z<58);Z=getchar_unlocked()){num=num*10+Z-48;}if(negat){num*=-1;}}
ll mm(ll a, ll b, ll m) {ll ans=a*b-m*ll(1.L/m*a*b);return ans+m*(ans<0)-m*(ans>=m);}
ll Pow(ll a, ll b, ll mod) {ll ans=1;for (; b;a=mm(a,a,mod),b/=2) {if (b&1) ans=mm(ans,a,mod);}return ans;}
ll P_Pow[1000005];
void construct() {
	P_Pow[1000004]=1;
	for (int i=1000003;i>=0;i--) P_Pow[i]=(P_Pow[i+1]*26)%MOD;
	return;
	}
int solve(str s) {
	ll curr,hash1=0,hash2=0,prime=26LL;int ret=0;
	FOR (i,0,sz(s)) {
		curr=ll(s[i]);
		hash1=(hash1*prime+curr)%MOD;
		hash2=((hash2+curr*P_Pow[1000004-i]%MOD))%MOD;
		if (hash1==hash2) ret=i+1;
	}
	return ret;
	
}
int main() {
	boost;
	str s;
	construct();
	FOR (_,0,10) {
		cin >> s;
		int res1=solve(s);
		reverse(all(s));
		int res2=solve(s);
		cout << sz(s)-max(res1,res2) << "\n";
	}
	return 0;
}

