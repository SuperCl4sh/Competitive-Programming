/*
ID: 
TASK: butter
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

int dist[805][805];

int main() {
	boost;
	mem(dist,0x3f3f3f);
	freopen("butter.in","r",stdin);
	freopen("butter.out","w",stdout);
	int a,b,d,n,p,c;
	Read(n);Read(p);Read(c);
	int ar[n];
	FOR (i,0,n) {
		Read(ar[i]);
	}
	
	FOR (i,0,c) {
		Read(a);Read(b);Read(d);
		dist[a][b]=d,dist[b][a]=d;
	}
	FOR (i,1,p+1) {
		dist[i][i]=0;	
	}
	clock_t start=clock();
	FOR (k,1,p+1) {
		FOR (i,1,p+1) {
			if (dist[i][k]==INF) continue;
			FOR (j,1,i) {
				if (dist[k][j]!=INF&&dist[i][k]+dist[k][j]<dist[i][j]) dist[i][j]=dist[i][k]+dist[k][j],dist[j][i]=dist[i][k]+dist[k][j];
			}
		}
	}
	ll best=INF;
	FOR (i,1,p+1) {
		ll curr=0;
		FOR (j,0,n) {
			curr+=dist[i][ar[j]];
		}
		best=min(best,curr);
	}
	cout << best << "\n";
	
	return 0;
}
