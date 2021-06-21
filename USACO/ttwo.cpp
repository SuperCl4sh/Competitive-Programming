/*
ID: 
TASK: ttwo
LANG: C++                 
*/

#include <bits/stdc++.h>
#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
using namespace std;
ofstream fout ("ttwo.out");
ifstream fin ("ttwo.in");
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
int main() {
	boost;

	str s;
	int fx,fy,cx,cy,dir=0,dir2=0;
	FOR (i,0,10) {
		fin >> s;
		grid.pb(s);
		FOR (j,0,sz(s)) {
			if (s[j]=='F') fx=i,fy=j;
			else if (s[j]=='C') cx=i,cy=j;
		}
	}
	int ans=0;
	while (1) {
		if (cx==fx&&cy==fy) break;
		if (dir==0) {
			if (fx>0&&grid[fx-1][fy]!='*') {
				fx--;
			}
			else dir++;
		}
		else if (dir==1) {
			if (fy<9&&grid[fx][fy+1]!='*') fy++;
			else dir++;
		}
		else if (dir==2) {
			if (fx<9&&grid[fx+1][fy]!='*') fx++;
			else dir++;
		}
		else {
			if (fy>0&&grid[fx][fy-1]!='*') fy--;
			else dir++;
		}
		if (dir2==0) {
			if (cx>0&&grid[cx-1][cy]!='*') {
				cx--;
			}
			else dir2++;
		}
		else if (dir2==1) {
			if (cy<9&&grid[cx][cy+1]!='*') cy++;
			else dir2++;
		}
		else if (dir2==2) {
			if (cx<9&&grid[cx+1][cy]!='*') cx++;
			else dir2++;
		}
		else {
			if (cy>0&&grid[cx][cy-1]!='*') cy--;
			else dir2++;
		}
		
		if (ans>1000) {ans=0;break;} //if statement > boolean array

		dir%=4;
		dir2%=4;
		++ans;
		
	}
	fout << ans << "\n";


	return 0;
}

