/*
ID:
TASK: 
LANG: C++                 
*/

#include <bits/stdc++.h>
using namespace std;
//ofstream fout (".out");
//ifstream fin (".in");
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

void fib(ull n) {
	ull start[2][2]={{1ULL,1ULL},{1ULL,0ULL}},mult[2][2]={{1ULL,1ULL},{1ULL,0ULL}};
	while (n) {
		ull New[2][2];
		mem(New,0ULL);
		if (n&1) {
			FOR (i,0,2) {
				FOR (j,0,2) {
					FOR (k,0,2) {
						New[i][j]=(New[i][j]+(start[i][k]%MOD)*(mult[k][j]%MOD))%MOD;
					}
				}
			}
			FOR (i,0,2) {
				FOR (j,0,2) start[i][j]=New[i][j]; 
			}
		}
		mem(New,0ULL);
		FOR (i,0,2) {
			FOR (j,0,2) {
				FOR (k,0,2) {
					New[i][j]=(New[i][j]+((mult[i][k]%MOD)*(mult[k][j]%MOD)))%MOD;
				}
			}
		}
		FOR (i,0,2) {
			FOR (j,0,2) mult[i][j]=New[i][j];
		}
		n>>=1;

	}
	cout << start[1][1]%MOD << "\n";


	return;
}

int main() {
	boost;
	
	ull n;
	cin >> n;

	fib(n);

	return 0;
}