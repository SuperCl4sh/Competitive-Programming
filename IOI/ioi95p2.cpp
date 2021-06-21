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

vt<vt<pll>>deals;
ll price[105],price2[105],ar[5],dp[6][6][6][6][6];
vt<pll>arr;

int check(int a) {
	int start=0;
	while (start<5) {
		if (ar[start]==a) return start;
		else if (ar[start]==-1) {ar[start]=a;return start;}
		++start;
	}
	assert(0);
	return 1;
}

ll solve (int a, int b, int c,int d, int e) {
	if (a<0||b<0||c<0||d<0||e<0) return INF;
	else if (a==0&&b==0&&c==0&&d==0&&e==0) return 0;
	else if (dp[a][b][c][d][e]!=-1) return dp[a][b][c][d][e];
	ll ret=INF;
	int A=a,B=b,C=c,D=d,E=e;
	FOR (i,0,sz(deals)) {
		int ind;
		FOR (j,0,sz(deals[i])) {
			ind=deals[i][j].F;
			if (ind==0) a-=deals[i][j].S;
			else if (ind==1) b-=deals[i][j].S;
			else if (ind==2) c-=deals[i][j].S;
			else if (ind==3) d-=deals[i][j].S;
			else if (ind==4) e-=deals[i][j].S;
		}
		ret=min(ret,solve(a,b,c,d,e)+price[i]);
		a=A,b=B,c=C,d=D,e=E;

	}
	ll res=INF;
	FOR (j,0,sz(arr)) {
		int ind=check(arr[j].F);
		if (ind==0) {
			res=solve(a-1,b,c,d,e);	
		}
		else if (ind==1) {
			res=solve(a,b-1,c,d,e);
		}
		else if (ind==2) {
			res=solve(a,b,c-1,d,e);
		}
		else if (ind==3) {
			res=solve(a,b,c,d-1,e);
		}
		else res=solve(a,b,c,d,e-1);
		ret=min(ret,res+arr[j].S);
	}

	
	return dp[a][b][c][d][e]=ret;
}

int main() {
	boost;
	mem(ar,-1);
	mem(dp,-1);
	ll a,b,c,d,s,ind;
	cin >> s;
	FOR (i,0,s) {
		cin >> a;
		vt<pll>curr;
		FOR (j,0,a) {
			cin >> b >> c;
			ind=check(b);
			curr.pb(mp(ind,c));
		}
		cin >> price[i];
		deals.pb(curr);
	}
	cin >>b;
	ll target[5];
	mem(target,0);
	FOR (i,0,b) {
		cin >> a >> c >> d;
		ind=check(a);
		arr.pb(mp(a,d));
		target[ind]+=c;
	}
	cout << solve(target[0],target[1],target[2],target[3],target[4]) << "\n";



	return 0;
}