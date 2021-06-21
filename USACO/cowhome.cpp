/*
ID: 
TASK: comehome
LANG: C++                 
*/

#include <bits/stdc++.h>
using namespace std;
ofstream fout ("comehome.out");
ifstream fin ("comehome.in");
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
ll modmul(ll a, ll b, ll m) {ll ans=a*b-m*ll(1.L/m*a*b);return ans+m*(ans<0)-m*(ans>=m);}
ll Pow(ll a, ll b, ll mod) {ll ans=1;for (; b;a=modmul(a,a,mod),b/=2) {if (b&1) ans=modmul(ans,a,mod);}return ans;}

vector<vector<pii>>adj(60);
str alphabet="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
bool visited[60];
int bfs(int node) {
	mem(visited,0);
	priority_queue<pii,vector<pii>,greater<pii>>pq;
	pq.P(mp(0,node));
	int dist,curr;
	while (!pq.empty()) {
		dist=pq.top().F,curr=pq.top().S;
		pq.pop();
		if (curr==25) break;
		if (visited[curr]) continue;
		visited[curr]=1;
		FOR (i,0,sz(adj[curr])) {
			pq.P(mp(dist+adj[curr][i].S,adj[curr][i].F));
		}
	}
	return (curr==25)?dist:INT_MAX;
}

int main() {
	boost;
	int a,b,e,f,p;char c,d;
	fin >> p;
	FOR (i,0,p) {
		fin >> c >> d;
		fin >> a;
		if (c==d) continue;
		if (isupper(c)) e=c-'A';
		else e=c-'a'+26;
		if (isupper(d)) f=d-'A';
		else f=d-'a'+26;
		adj[e].pb(mp(f,a));
		adj[f].pb(mp(e,a));
		//cout << c << ": " << e << " " << d << ": " << f << "\n";	
	}
	char g;
	int ans=INT_MAX;

	FOR (i,0,25) {
		if (!adj[i].empty()) {
			int curr=bfs(i);
			if (curr<ans) ans=curr,g=alphabet[i]; 

		}
	}
	fout << g << " "<<ans << "\n";
	

	

	return 0;
}
