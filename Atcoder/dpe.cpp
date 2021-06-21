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
#define upper_bound ub
#define lower_bound lb
#define FOR(i,a,n,b) for (int i=a;i<n;i+=b)
#define vt vector
#define rtn return
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
const int INF=10000;
void read(auto &num) {register int Z;num=0;bool negat=0;Z=getchar();if (Z=='-') {negat=1;Z=getchar();}for(;(Z>47&&Z<58);Z=getchar()){num=num*10+Z-48;}if(negat){num*=-1;}}
void Read(auto &num) {register int Z;num=0;bool negat=0;Z=getchar_unlocked();if (Z=='-') {negat=1;Z=getchar_unlocked();}for(;(Z>47&&Z<58);Z=getchar_unlocked()){num=num*10+Z-48;}if(negat){num*=-1;}}
ll modmul(ll a, ll b, ll m) {ll ans=a*b-m*ll(1.L/m*a*b);return ans+m*(ans<0)-m*(ans>=m);}
ll Pow(ll a, ll b, ll mod) {ll ans=1;for (; b;a=modmul(a,a,mod),b/=2) {if (b&1) ans=modmul(ans,a,mod);}return ans;}
ll Pow(ll a, ll b) {ll ret=1;while (b) {if (b&1) ret*=a;a*=a;b>>=1;}return ret;}
void Time(clock_t start) {printf("Process took %lf seconds.\n",(clock()-start)/double(CLOCKS_PER_SEC));return;}
int dx8[8]={1,1,-1,-1,2,2,-2,-2},dy8[8]={2,-2,2,-2,1,-1,1,-1}; //:)
clock_t start;
/*--------------------------------------------------------------PROGRAM START-------------------------------------------------------------------------*/

int main() {
	int a,b,n,w;
	cin >> n >> w;
	ll dp[100005];
	mem(dp,0x3f3f);
	dp[0]=0;
	FOR (i,0,n,1) {
		cin >> a >> b;
		for (int j=(int)(1e5);j>=b;j--) if (dp[j-b]+a<=w) dp[j]=min(dp[j],dp[j-b]+a); 
	}
	int ans=0;
	for (int i=(int)(1e5);i>=0;i--) if (dp[i]<=w) {ans=i;break;}
	cout << ans << "\n";

	return 0;
}
//similar to the last problem, brute force suffices to AC (DMOJ only)
