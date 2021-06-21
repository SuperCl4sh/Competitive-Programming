/*
ID: 
TASK: concom
LANG: C++                 
*/

#include <bits/stdc++.h>
#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
using namespace std;
ofstream fout ("concom.out");
ifstream fin ("concom.in");
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
ll modmul(ll a, ll b, ll m) {ll ans=a*b-m*ll(1.L/m*a*b);return ans+m*(ans<0)-m*(ans>=m);}
ll Pow(ll a, ll b, ll mod) {ll ans=1;for (; b;a=modmul(a,a,mod),b/=2) {if (b&1) ans=modmul(ans,a,mod);}return ans;}

bool change=1,changed[105][105],visited[105],own[105][105],seen[105],done[105][105];int curr=0,adj[105][105],compare,start=0;

void dfs(int node) {
	if (visited[node]||curr>50) return;
	visited[node]=1;
	curr+=adj[node][compare];
	FOR (i,1,105) {
		if (i==node) continue;
		else if (own[node][i]) dfs(i);
	}
	return;
}
void update(int node) {
	if (visited[node]) return;
	visited[node]=1;
	if (!own[start][node]) {change=1;}
	own[start][node]=1;
	FOR (i,1,105) {
		if (own[node][i]) update(i);
	}
	return;
}

int main() {
	boost;
	int a,b,c,n;
	fin >> n;
	FOR (i,0,n) {
		fin >> a >> b >> c;
		seen[a]=1,seen[b]=1;
		adj[a][b]+=c;
		if (c>50) own[a][b]=1;
	}
	vector<pii>ans;
	while (change) {
		mem(changed,0);
		change=0;
	FOR (i,1,105) {
		if (!seen[i]) continue;
		FOR (j,1,105) {
			if (!seen[j]||i==j||own[i][j]) continue;
			curr=0;
			mem(visited,0);
			compare=j;
			dfs(i);
			if (curr>50) {change=1;own[i][j]=1;}
			
		}
	}
	FOR (i,1,105) {
		if (!seen[i]) continue;
		FOR (j,1,105) {
			if (!seen[j]||i==j||!own[i][j]) continue;
			mem(visited,0);
			start=i;
			update(j);
		}
	}
	}
	FOR (i,1,105) {
		if (!seen[i]) continue;
		FOR (j,1,105) {
			if (!seen[j]||i==j) continue;
			if (own[i][j]) ans.pb(mp(i,j));
		}
	}	
	sort(all(ans));
	FOR (i,0,sz(ans)) 
		fout << ans[i].F << " " << ans[i].S << "\n";
	
	
	return 0;
}
//0.8s worst case :)

