//https://dmoj.ca/problem/ccc98s5
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
using namespace std;
#define mp make_pair
#define pb push_back
#define pf push_front
#define PF pop_front
#define PB pop_back
#define P push
#define F first
#define S second
#define scann(speed){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}speed=s*f;}
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define make_tuple MT
#define PI 3.14159265
#define len(s) (int)s.length()
#define sz(s) (int)s.size()
#define sp(x) fixed << setprecision(x)
typedef long long ll;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;
typedef pair<double,double>pdd;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ld,ld>pld;
typedef pair<str,str>pss;
typedef pair<char,char>pcc;
typedef pair<long,long>pl;
char _;
const ll MOD = 1000000007;
const ll mxN= (ll)(1e15);
void read(auto &num) {register int Z;num=0;bool negat=0;Z=getchar();if (Z=='-') {negat=1;Z=getchar();}for(;(Z>47&&Z<58);Z=getchar()){num=num*10+Z-48;}if(negat){num*=-1;}}
int adj[30][30],b,start;bool visited[30][30];
priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>>pq;
void bfs() {
while (!pq.empty()) pq.pop();
pq.P(mp(0,mp(1,1)));
int x,y,oxygen;
while (!pq.empty()) {
	oxygen=pq.top().F;
	x=pq.top().S.F;
	y=pq.top().S.S;
	pq.pop();
	if (x==b&&y==b) {printf("%i\n",oxygen);return;}
	if (visited[x][y]) continue;
	visited[x][y]=1;
	if (x>1) {
		if (abs(adj[x][y]-adj[x-1][y])<=2) {
			(adj[x][y]<=start&&adj[x-1][y]<=start)?pq.P(mp(oxygen,mp(x-1,y))):pq.P(mp(oxygen+1,mp(x-1,y)));
		}
	}
	if (y>1) {
		if (abs(adj[x][y]-adj[x][y-1])<=2) {
			(adj[x][y]<=start&&adj[x][y-1]<=start)?pq.P(mp(oxygen,mp(x,y-1))):pq.P(mp(oxygen+1,mp(x,y-1)));
		}
	}
	if (x<b) {
		if (abs(adj[x][y]-adj[x+1][y])<=2) {
			(adj[x][y]<=start&&adj[x+1][y]<=start)?pq.P(mp(oxygen,mp(x+1,y))):pq.P(mp(oxygen+1,mp(x+1,y)));
		}
	}
	if (y<b) {
		if (abs(adj[x][y]-adj[x][y+1])<=2) {
			(adj[x][y]<=start&&adj[x][y+1]<=start)?pq.P(mp(oxygen,mp(x,y+1))):pq.P(mp(oxygen+1,mp(x,y+1)));
		}
	}
}
printf("CANNOT MAKE THE TRIP\n");
return;
}
int main() {
	boost;
	int n;
	read(n);
	for (int i=0;i<n;i++) {
		read(b);
		memset(adj,0,sizeof(adj));
		for (int j=1;j<=b;j++) {
			for (int k=1;k<=b;k++) {
				read(adj[j][k]);
			}
		}
		start=adj[1][1];
		memset(visited,0,sizeof(visited));
		bfs();
	}	

	return 0;
}
