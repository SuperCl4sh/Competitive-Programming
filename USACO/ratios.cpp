/*
ID: 
TASK: ratios
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
const int INF=0x3f3f3f;
void read(auto &num) {register int Z;num=0;bool negat=0;Z=getchar();if (Z=='-') {negat=1;Z=getchar();}for(;(Z>47&&Z<58);Z=getchar()){num=num*10+Z-48;}if(negat){num*=-1;}}
void Read(auto &num) {register int Z;num=0;bool negat=0;Z=getchar_unlocked();if (Z=='-') {negat=1;Z=getchar_unlocked();}for(;(Z>47&&Z<58);Z=getchar_unlocked()){num=num*10+Z-48;}if(negat){num*=-1;}}
ll modmul(ll a, ll b, ll m) {ll ans=a*b-m*ll(1.L/m*a*b);return ans+m*(ans<0)-m*(ans>=m);}
ll Pow(ll a, ll b, ll mod) {ll ans=1;for (; b;a=modmul(a,a,mod),b/=2) {if (b&1) ans=modmul(ans,a,mod);}return ans;}
ll Pow(ll a, ll b) {ll ret=1;while (b) {if (b&1) ret*=a;a*=a;b>>=1;}return ret;}
/*--------------------------------------------------------------PROGRAM START-------------------------------------------------------------------------*/
int a,b,c,ar[3][3];
int main() {
	boost;
	freopen("ratios.in","r",stdin);
	freopen("ratios.out","w",stdout);
	cin >> a >> b >> c;
	FOR (i,0,3) {
		cin >> ar[i][0] >> ar[i][1] >> ar[i][2];
	}
	int currTot=0,bestTot=INF,bestI=0,bestJ=0,bestK=0,A,B,C,Ratio=0;bool done=0;
	FOR (i,0,101) {
		A=ar[0][0]*i,B=ar[0][1]*i,C=ar[0][2]*i;
		FOR (j,0,101) {
			A+=ar[1][0]*j,B+=ar[1][1]*j,C+=ar[1][2]*j;
			FOR (k,0,101) {
				bool bad=0,bad2=0;
				A+=ar[2][0]*k,B+=ar[2][1]*k,C+=ar[2][2]*k;
				currTot=i+j+k;
				if (a==0&&A>0) bad=1;
				if (b==0&&B>0) bad=1;
				if (c==0&&C>0) bad=1;
				if (!bad) {
					if (A%max(a,1)||B%max(b,1)||C%max(c,1)) bad2=1;
					if (!bad2) {
						if (currTot<bestTot&&(a==0||b==0||A/max(a,1)==B/max(b,1))&&(b==0||c==0||B/max(b,1)==C/max(c,1))&&currTot>0) {
							bestTot=currTot,bestI=i,bestJ=j,bestK=k,Ratio=A/max(a,1);
							done=1;
						}
					}
				
				}
				A-=ar[2][0]*k,B-=ar[2][1]*k,C-=ar[2][2]*k;
			
			}
			A-=ar[1][0]*j,B-=ar[1][1]*j,C-=ar[1][2]*j;
		}
	}
	if (done) {
		cout << bestI << " " << bestJ << " " << bestK << " " << Ratio << "\n";
	}
	else cout << "NONE\n";
	return 0;
}

