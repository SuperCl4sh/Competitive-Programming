#include <bits/stdc++.h>
#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
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
typedef long long ll;
typedef string str;
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
const ll MOD = 1000000007;
const ll high= (ll)(1e15);
const ll MOD2=998244353;
void read(auto &num) {register int Z;num=0;bool negat=0;Z=getchar();if (Z=='-') {negat=1;Z=getchar();}for(;(Z>47&&Z<58);Z=getchar()){num=num*10+Z-48;}if(negat){num*=-1;}}
void Read(auto &num) {register int Z;num=0;bool negat=0;Z=getchar_unlocked();if (Z=='-') {negat=1;Z=getchar_unlocked();}for(;(Z>47&&Z<58);Z=getchar_unlocked()){num=num*10+Z-48;}if(negat){num*=-1;}}
int r,c,sx,sy,Sy,Sx,dp[105][105],d1[8]={1,1,2,2,-1,-1,-2,-2},d2[8]={2,-2,1,-1,2,-2,1,-1};
void Solve() {
	for (int i=0;i<105;i++) {
		for (int j=0;j<105;j++) {
			dp[i][j]=100000;
		}
	}
	queue<pii>q;
	dp[sx][sy]=0;
	q.P(mp(sx,sy));
	int x,y;
	while (!q.empty()) {
		x=q.front().F;y=q.front().S;
		q.pop();
		for (int i=0;i<8;i++) {
			if (x+d1[i]<r&&x+d1[i]>=0&&y+d2[i]<c&&y+d2[i]>=0) {
				if (dp[x+d1[i]][y+d2[i]]>dp[x][y]+1) {
					dp[x+d1[i]][y+d2[i]]=dp[x][y]+1;
					q.P(mp(x+d1[i],y+d2[i]));
				}
			}
		}
		
	}
	y=Sy;bool stalemate=0;int moves;
	for (int i=0;i<Sx;i++) {
		if (dp[Sx-i][y]==i) {
			printf("Win in %i knight move(s).\n",i);
			return;
		}
		else if ((i-dp[Sx-i][y])%2==0&&dp[Sx-i][y]<i) {
			printf("Win in %i knight move(s).\n",i);
			return;
		}
		if (dp[Sx-1-i][y]==i&&!stalemate) {
			stalemate=1;
			moves=i;
		}
		

	}
	if (stalemate) {
		printf("Stalemate in %i knight move(s).\n",moves);
	}
	else {
		printf("Loss in %i knight move(s).\n",Sx-1);
	}
	return;
}
int main() {
	boost;
	int n;
	cin >> n;
	for (int i=0;i<n;i++) {
		cin >> r >> c >> Sx >> Sy >> sx >> sy;
		Sx=r-Sx;sx=r-sx;Sy--,sy--;
		Solve();
	}

	return 0;
}