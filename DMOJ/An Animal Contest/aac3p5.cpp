//https://dmoj.ca/problem/aac3p5
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
*/
//^speed
//typedefs
typedef long long ll;
typedef string str;
typedef pair<int,int> pii;
typedef long double ld;
typedef unsigned long long ull;
//defines
#define mp make_pair
#define pb push_back
#define pf push_front
#define PF pop_front
#define PB pop_back
#define P push
#define F first
#define S second
#define fr front()
#define bk back()
#define boost ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define sz(s) (int)s.size()
#define sp(x) cout << fixed << setprecision(x)
#define all(a) a.begin(),a.end()
#define mem(ar,a) memset(ar,a,sizeof(ar))
#define FOR(i,a,n,b) for (int i=a;i<n;i+=b)
#define rep(i,a,n) FOR (i,a,n,1)
#define ROF(i,a,n,b) for (int i=a;i>n;i-=b) 
#define vt vector
#define EACH(a,b) for (auto &a: b) 
#define rtn return
#define each(a,b) for (auto a: b)
#define pc putchar
#define gc getchar
//input
template <typename T> void read(T& a) {
	cin >> a;
}
template<typename A, typename B> void read(pair<A,B> &a) {
	read(a.F);read(a.S);
}
template <typename A> void read(vt<A>&ar) {
	EACH(a,ar) read(a);

}
template <typename A, typename... Types> void read(A&  num, Types&... num1) {
	read(num);read(num1...);
}
//output
template<typename T>void out(T a) {
	cout << a;
}
void out(const char *s) {
	rep (i,0,strlen(s)) {
		out(s[i]);
	}
}
template<typename A,typename B> void out(pair<A,B>a) {
	out(a.F);
	out(' ');
	out(a.S);
}
template<typename T> void out(vt<T>ar) {
	rep (i,0,sz(ar)) {
		out(ar[i]);
		if (i+1<sz(ar)) cout << ' ';

	}
}
template <typename A, typename... Types> void out(A s, Types... s1) {
	out(s);
	if (sizeof...(s1)) out(' ');
	out(s1...);
}
void write() {}
template<typename A, typename... types> void write(A s, types... s1) {
	out(s);
	write(s1...);
}
template<typename A, typename... types> void writeln(A s, types... s1) {
	out(s);
	write(s1...,'\n');
}
template<typename A> void writeln(A s) {
	out(s,'\n');
}
template<typename A> void outln(A s) {
	out(s);
	out('\n');
}
template<typename A, typename... types> void outln(A s, types... s1) {
	out(s);
	if (sizeof...(s1)) out(' ');
	out(s1...);
	out('\n');
}

template <typename T,typename A> T Pow(T a, A b) {
	T ret=1;
	while (b) {
		if (b&1) ret*=a;a*=a;b>>=1;
	}
	rtn ret;
}
template <typename T, typename A, typename B> T Pow(T a, A b, B mod) {
	T ret=1;
	while (b) {
		if (b&1) ret=(ret*a)%mod;a=(a*a)%mod;b>>=1;
	}
	assert(ret>=0);
	rtn ret;
}
//constants
const int dx8[8]={1,1,-1,-1,2,2,-2,-2},dy8[8]={2,-2,2,-2,1,-1,1,-1},dx4[4]={1,-1,0,0},dy4[4]={0,0,1,-1}; 
/*--------------------------------------------------------------PROGRAM START-------------------------------------------------------------------------*/
const int mxN=(int)(2e3);
const int mxM=(int)(2e3);
vt<str>grid(1);
pii Left[mxN+5][mxM+5];
pii Right[mxN+5][mxM+5];
pii Up[mxN+5][mxM+5];
pii Down[mxN+5][mxM+5];
int N,M;
int vis[mxN+1][mxM+1];
int INF=(int)(1e9);
pii dfs_left(int r, int c) {
	if (r<=0||r>N||c<=0||c>M) rtn {-1,-1};
	else if (Left[r][c].F!=-1&&Left[r][c].S!=-1) rtn Left[r][c];
	else if (grid[r][c]!='.') rtn {r,c};
	rtn Left[r][c]=dfs_left(r,c-1);
}
pii dfs_right(int r, int c) {
	if (r<=0||r>N||c<=0||c>M) rtn {-1,-1};
	else if (Right[r][c].F!=-1&&Right[r][c].S!=-1) rtn Right[r][c];
	else if (grid[r][c]!='.') rtn {r,c};
	rtn Right[r][c]=dfs_right(r,c+1);
}
pii dfs_up(int r, int c) {
	if (r<=0||r>N||c<=0||c>M) rtn {-1,-1};
	else if (Up[r][c].F!=-1&&Up[r][c].S!=-1) rtn Up[r][c];
	else if (grid[r][c]!='.') rtn {r,c};
	rtn Up[r][c]=dfs_up(r-1,c);
}
pii dfs_down(int r, int c) {
	if (r<=0||r>N||c<=0||c>M) rtn {-1,-1};
	else if (Down[r][c].F!=-1&&Down[r][c].S!=-1) rtn Down[r][c];
	else if (grid[r][c]!='.') rtn {r,c};
	rtn Down[r][c]=dfs_down(r+1,c);
}
void solve (int sx, int sy) {
	priority_queue<pair<int,pii>>pq;
	pq.P(mp(INF,mp(sx,sy)));
	vis[sx][sy]=INF;
	while (!pq.empty()) {
		int canoe=pq.top().F,x=pq.top().S.F,y=pq.top().S.S;
		pq.pop();
		if (x<=0||y<=0||x>N||y>M) continue;
		else if (vis[x][y]>canoe) continue;
		rep (i,0,4) {
			int nx=dx4[i]+x,ny=dy4[i]+y;
			if (nx<=0||ny<=0||nx>N||ny>M) continue;
			if (grid[nx][ny]=='.') {
				int nxtx,nxty;
				if (i==0) nxtx=Down[nx][ny].F,nxty=Down[nx][ny].S; //down
				else if (i==1) nxtx=Up[nx][ny].F,nxty=Up[nx][ny].S; //up
				else if (i==2) nxtx=Right[nx][ny].F,nxty=Right[nx][ny].S; //right
				else nxtx=Left[nx][ny].F,nxty=Left[nx][ny].S; //left
				if (nxtx!=-1) {
					int req=max(abs(nxtx-x),abs(nxty-y))-1;
					if (min(req,canoe)>vis[nxtx][nxty]) {vis[nxtx][nxty]=min(req,canoe);pq.P(mp(min(req,canoe),mp(nxtx,nxty)));}
				}

			}
			else {
				if (vis[nx][ny]<canoe) {vis[nx][ny]=canoe;pq.P(mp(canoe,mp(nx,ny)));}
			}
		}
	}
}
int main() {
	boost;
	mem(vis,-1);
	read(N,M);
	rep (i,1,N+1) {
		rep (j,1,M+1) Left[i][j]={-1,-1},Right[i][j]={-1,-1},Down[i][j]={-1,-1},Up[i][j]={-1,-1};
	}
	rep (i,0,N) {
		str row;read(row);
		row.insert(0," ");grid.pb(row);
	}
	rep (i,1,N+1) {
		rep (j,1,M+1) {
			if (grid[i][j]=='.') {
				dfs_left(i,j);
				dfs_right(i,j);
				dfs_down(i,j);
				dfs_up(i,j);
			}
		}
	}
	rep (i,1,M+1) {
		if (grid[1][i]=='#') solve(1,i);
	}
	vt<int>ans;
	rep (i,1,M+1) {
		ans.pb((vis[N][i]==INF)?0:vis[N][i]);
	}
	outln(ans);
	rtn 0;
}
