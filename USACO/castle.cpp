/*
ID:
TASK: castle 
LANG: C++                 
*/
#include <bits/stdc++.h>
#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
using namespace std;
ofstream fout ("castle.out");
ifstream fin ("castle.in");
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
int n,m,grid[51][51][4],curr=0;
int num=0,calc[2501],grid2[51][51];
vector<pii>d4={{-1,0},{0,1},{1,0},{0,-1}};
bool visited[51][51];
int bfs(int i, int j) {
	queue<pii>q;
	int x,y,ret=0;
	q.P(mp(i,j));
	while (!q.empty()) {
		x=q.front().F,y=q.front().S;
		q.pop();
		if (x<0||y<0||x>=n||y>=m) continue;
		if (visited[x][y]) continue;
		visited[x][y]=1;
		++ret;
		grid2[x][y]=num;
		for (int k=0;k<4;k++) {
			if (!grid[x][y][k]) {
				q.P(mp(d4[k].F+x,d4[k].S+y));
			}
		}
	}
	return ret;
	
}
int main() {
	boost;
	fin >> m >> n;
	int change=0,start=0;
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			fin >> start;
			while (start>0) {
				change=start&(-start);
				if (change==1) {
					grid[i][j][3]=1;
				}
				else if (change==2) {
					grid[i][j][0]=1;
				}
				else if (change==4) {
					grid[i][j][1]=1;
				}
				else if (change==8) {
					grid[i][j][2]=1;
				}
				start-=change;
			}
		}
	}
	mem(calc,-1);
	for (int i=0;i<51;i++) {
		for (int j=0;j<51;j++) grid2[i][j]=-1;
	}
	int ans=0;
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			if (visited[i][j]) continue;
			calc[num]=bfs(i,j);
			ans=max(ans,calc[num]);
			++num;	
		}
	}
	
	int ans2=0,x,y;char dir='E';
	for (int j=0;j<m;j++) {
		for (int i=n-1;i>=0;i--) {
			if (i>0) {
				if (grid2[i][j]!=grid2[i-1][j]) {
					int temp=calc[grid2[i][j]]+calc[grid2[i-1][j]];
					if (temp>ans2) {
						ans2=temp;
						x=i;
						y=j;
						dir='N';
					}
				}
			}
			if (j<m-1) {
				if (grid2[i][j]!=grid2[i][j+1]) {
					int temp=calc[grid2[i][j]]+calc[grid2[i][j+1]];
					if (temp>ans2) {
						ans2=temp;
						x=i;
						y=j;
						dir='E';
					}
				}
			}
		}
	}
	fout << num << "\n" << ans << "\n" << ans2 << "\n" << x+1 << " " <<y+1 << " " << dir << "\n";
	return 0;
}

