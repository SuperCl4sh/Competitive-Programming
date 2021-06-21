/*
ID: 
TASK: cowtour
LANG: C++                 
*/

#include <bits/stdc++.h>
using namespace std;
ofstream fout ("cowtour.out");
ifstream fin ("cowtour.in");
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
int n,id=0,adj[155][155];ld dist[155][155],bad=10000000.0;bool visited[155];
vector<vi>ids(155);

void dfs(int node) {
	if (visited[node]) return;
	visited[node]=1;
	ids[id].pb(node);
	FOR (i,0,n) {
		if (adj[node][i]) dfs(i);
	}
	return;
}

int main() {
	boost;
	fin >> n;
	ld a,b;
	pld pastures[n];
	FOR (i,0,n) {
		fin >> a >> b;
		pastures[i].F=a,pastures[i].S=b;
	}
	char s;
	FOR (i,0,n) {
		FOR (j,0,n) {
			fin >> s;
			adj[i][j]=s-'0'==1;
			if (s-'0'==1) dist[i][j]=(ld)(sqrt(pow(pastures[i].F-pastures[j].F,2)+pow(pastures[i].S-pastures[j].S,2)));
			else dist[i][j]=bad;
		}	
	}
	
		
	FOR (k,0,n) {
		FOR (i,0,n) {
			FOR (j,0,n) {
				if (dist[i][k]+dist[k][j]<dist[i][j]&&dist[i][k]!=bad&&dist[k][j]!=bad) dist[i][j]=dist[i][k]+dist[k][j];
			}
		}
	}
	FOR (i,0,n) dist[i][i]=bad;
	
	ld highest[n],ans2=0;
	mem(highest,0);
	FOR (i,0,n) {
		FOR (j,0,n) {
			if (dist[i][j]==bad) continue;
			highest[i]=max(highest[i],dist[i][j]);
		
		}
		ans2=max(ans2,highest[i]);
	}
	
	FOR (i,0,n) {
		if (!visited[i]) {
			dfs(i);
			++id;
		}
	}
	ld ans=bad;
	FOR (i,0,id) {
		FOR (j,i+1,id) {
			for (auto node: ids[i]) {
				for (auto node2: ids[j]) {
					ans=min(ans,highest[node]+highest[node2]+sqrt(pow(pastures[node].F-pastures[node2].F,2)+pow(pastures[node].S-pastures[node2].S,2)));
					
				}
			}
		}
	}
	fout << sp(6) << max(ans,ans2) << "\n";

	return 0;
}
//tfw you incorrectly implement an algorithm and spend hours debugging D:

