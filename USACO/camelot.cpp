/*
ID: 
TASK: camelot
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
#define upper_bound ub
#define lower_bound lb
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
const int INF=0x3f3f3f3f;
void read(auto &num) {register int Z;num=0;bool negat=0;Z=getchar();if (Z=='-') {negat=1;Z=getchar();}for(;(Z>47&&Z<58);Z=getchar()){num=num*10+Z-48;}if(negat){num*=-1;}}
void Read(auto &num) {register int Z;num=0;bool negat=0;Z=getchar_unlocked();if (Z=='-') {negat=1;Z=getchar_unlocked();}for(;(Z>47&&Z<58);Z=getchar_unlocked()){num=num*10+Z-48;}if(negat){num*=-1;}}
ll modmul(ll a, ll b, ll m) {ll ans=a*b-m*ll(1.L/m*a*b);return ans+m*(ans<0)-m*(ans>=m);}
ll Pow(ll a, ll b, ll mod) {ll ans=1;for (; b;a=modmul(a,a,mod),b/=2) {if (b&1) ans=modmul(ans,a,mod);}return ans;}
ll Pow(ll a, ll b) {ll ret=1;while (b) {if (b&1) ret*=a;a*=a;b>>=1;}return ret;}
void Time(clock_t start) {printf("Process took %lf seconds.\n",(clock()-start)/double(CLOCKS_PER_SEC));return;}
/*--------------------------------------------------------------PROGRAM START-------------------------------------------------------------------------*/
int r,c,dx8[8]={1,1,-1,-1,2,2,-2,-2},dy8[8]={2,-2,2,-2,1,-1,1,-1},dp[31][27][31][27];bool visited[31][27];
vt<pii>knights;
void init() {
	queue<pii>q;
	mem(dp,0x3f3f3f);
	FOR (i,1,r+1) {
		FOR (j,1,c+1) {
			q.P(mp(i,j));
			int nx,ny,x,y;
			dp[i][j][i][j]=0;
			mem(visited,0);
			visited[i][j]=1;
			while (!q.empty()) {
				x=q.front().F,y=q.front().S;
				q.pop();
				FOR (z,0,8) {
					nx=x+dx8[z],ny=y+dy8[z];
					if (nx<1||ny<1||nx>r||ny>c) continue;
					else if (visited[nx][ny]) continue;
					dp[i][j][nx][ny]=dp[i][j][x][y]+1;
					visited[nx][ny]=1;
					q.P(mp(nx,ny));
				}	
			}
		}
	}
	return;
}
int main() {
	boost;
	freopen("camelot.in","r",stdin);
	freopen("camelot.out","w",stdout);
	clock_t start=clock();
	cin >> r >> c;
	char a;int b;
	cin >> a >> b;
	int sy=a-'A'+1,sx=b;
	while (1) {
		cin >> a >> b;
		if (cin.eof()) break;
		knights.pb(mp(b,a-'A'+1));
	}
	start=clock();
	init();
	//Time(start);
	start=clock();
	int change=3,ans=INF,nx,ny,SX=sx-change,EX=sx+change,SY=sy-change,EY=sy+change; //kinda sketch but it works :)
	SX=max(1,SX);
	EX=min(r,EX);
	SY=max(1,SY);
	EY=min(c,EY); 
	FOR (i,1,r+1) {
		FOR (j,1,c+1) {
			int curr=0,curr2,curr3;
			bool bad=0;
			FOR (k,0,sz(knights)) {
				if (dp[knights[k].F][knights[k].S][i][j]==INF) {bad=1;break;}
				curr+=dp[knights[k].F][knights[k].S][i][j];
			}
			if (bad) continue;
			curr2=max(abs(sx-i),abs(sy-j));
			FOR (w,SX,EX+1) {
				FOR (v,SY,EY+1) {
					FOR (k,0,sz(knights)) {
						if (dp[knights[k].F][knights[k].S][w][v]==INF||dp[w][v][i][j]==INF||dp[knights[k].F][knights[k].S][i][j]==INF) {
							break;
						}
						curr3=max(abs(sx-w),abs(sy-v))+dp[knights[k].F][knights[k].S][w][v]+dp[w][v][i][j]-dp[knights[k].F][knights[k].S][i][j];
						curr2=min(curr2,curr3);
					}
				}
			}
			
			
			ans=min(ans,curr2+curr);
		
		}
	}
	//Time(start);
	
	cout << ans << "\n";
	return 0;
}

