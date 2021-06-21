/*
ID: 
TASK: maze1
LANG: C++                 
*/

#include <bits/stdc++.h>
#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
using namespace std;
ofstream fout ("maze1.out");
ifstream fin ("maze1.in");
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
vector<str>grid;
int ans=0,dx[4]={1,0,0,-1},dy[4]={0,-1,1,0},h,w,dist[305][305];
bool visited[305][305];
void bfs(int r, int c) {
	mem(visited,0);
	priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>>pq;
	pq.P(mp(1,mp(r,c)));
	int curr,x,y;
	while (!pq.empty()) {
		curr=pq.top().F,x=pq.top().S.F,y=pq.top().S.S;
		pq.pop();
		if (x<0||y<0||x>2*h||y>2*w) continue;
		else if (visited[x][y]||grid[x][y]!=' ') continue;
		visited[x][y]=1;
		dist[x][y]=min(curr/2,dist[x][y]);
		FOR (i,0,4) {
			pq.P(mp(curr+1,mp(x+dx[i],y+dy[i])));
		}
	}

	
	
	
	return;
}

int main() {
	boost;
	FOR (i,0,305) {
		FOR (j,0,305) {
			dist[i][j]=INT_MAX;
		}
	}
	str s;
	getline(fin,s);
	str curr="";
	FOR (i,0,sz(s)) {
		if (!isdigit(s[i])) w=stoi(curr),curr="";
		else curr+=s[i];
	}
	h=stoi(curr);
	FOR (i,0,2*h+1) {
		getline(fin,s);
		grid.pb(s);
	}
	vector<pii>exit;
	FOR (i,0,sz(grid[0])) {
		if (grid[0][i]==' ') exit.pb(mp(0,i));
		if (grid[2*h][i]==' ') exit.pb(mp(2*h,i));
	}
	FOR (i,0,2*h) {
		if (grid[i][0]==' ') exit.pb(mp(i,0));
		if (grid[i][sz(grid[i])-1]==' ') exit.pb(mp(i,sz(grid[i])-1));
	}
	FOR (i,0,sz(exit)) {
		bfs(exit[i].F,exit[i].S);
	}
	int ans=0;
	FOR (i,0,305) {
		FOR (j,0,305) {
			if (dist[i][j]!=INT_MAX) ans=max(ans,dist[i][j]);
		}
	}
	fout << ans << "\n";


	return 0;
}
//tried BFSing for every space character and it TLEd ):
