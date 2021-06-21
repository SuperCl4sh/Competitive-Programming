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
vt<pii>knights;
int dp[9][9][9][9],convert[9]={-1,8,7,6,5,4,3,2,1};bool visited[9][9];

void init() {
	FOR (i,0,9,1) 
		FOR (j,0,9,1)
			FOR (k,0,9,1) 
				FOR (l,0,9,1) dp[i][j][k][l]=INF;
	mem(visited,0);
	FOR (i,1,9,1) {
		FOR (j,1,9,1) {
			mem(visited,0);
			dp[i][j][i][j]=0;
			queue<pii>q;
			q.P(mp(i,j));
			visited[i][j]=1;
			int x,y;
			while (!q.empty()) {
				x=q.front().F,y=q.front().S;
				q.pop();
				FOR (k,0,8,1) {
					int nx=x+dx8[k],ny=y+dy8[k];
					if (nx<1||ny<1||nx>8||ny>8) continue;
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
	str s;
	cin >> s;
	int sx=s[1]-'0',sy=s[0]-'A'+1;
	FOR (i,2,sz(s),2) {
		knights.pb(mp(s[i+1]-'0',s[i]-'A'+1));
	}
	init();
	int Change=8,ans=INF;
	FOR (i,1,9,1) {
		FOR (j,1,9,1) {
			int curr=0;
			FOR (k,0,sz(knights),1) curr+=dp[i][j][knights[k].F][knights[k].S];
			int change=max(abs(sx-i),abs(sy-j));
			FOR (w,1,9,1) {
				FOR (f,1,9,1) {
					FOR (k,0,sz(knights),1) {
						int newChange=max(abs(w-sx),abs(f-sy))+dp[knights[k].F][knights[k].S][w][f]+dp[w][f][i][j]-dp[knights[k].F][knights[k].S][i][j];
						change=min(change,newChange);
					}
				}
			}
			ans=min(ans,curr+change);
		}
	}
	cout << ans << "\n";



	return 0;
}