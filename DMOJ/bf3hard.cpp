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
ll mm(ll a, ll b, ll m) {
    ll ans=(__int128)(((__int128)((__int128)((__int128)(a)*(__int128)(b))-(__int128)(m)*(__int128)((__int128)(1.L)/(__int128)(m)*(__int128)(a)*(__int128)(b))))%(__int128(m)));
    return (__int128)(ans+(__int128)((__int128)(m)*(__int128)((ans<0))-(__int128)(m*(ans>=m))));}
//ll Pow(ll a, ll b, ll mod) {ll ans=1;for (; b;a=mm(a,a,mod),b/=2) {if (b&1) ans=mm(ans,a,mod);}return ans;}

ll Pow(ll a, ll b, ll c) {
	ll ret=1;
	while (b) {
		if (b&1) ret=(ll)(((__int128)(ret)*(__int128)(a))%(__int128)(c));
		a=(ll)(((__int128(a)*__int128(a))%(__int128(c))));
		b>>=1;
	}
	return ret;
}


bool isPrime(ll n) {
	if (n<2||n%6%4!=1) return (n|1)==3;
	ll primes[]={2LL, 325LL, 9375LL, 28178LL, 450775LL, 9780504LL, 1795265022LL};
	ll s=__builtin_ctzll(n-1);
	ll d=n>>s,p,i;
	for (ll a: primes) {
		p=Pow(a%n,d,n),i=s;
		while (p!=1&&p!=n-1&&a%n&&--i) {p=mm((__int128)(p),(__int128)(p),(__int128)(n));}
		if (p!=n-1&&i!=s) return 0;
	}
	int iterations=10000;
	while (iterations--) {
		ll a=rand()%(n-1)+2;
		p=Pow(a%n,d,n),i=s;
		while (p!=1&&p!=n-1&&a%n&&--i) {p=mm((__int128)(p),(__int128)(p),(__int128)(n));
		}
		if (p!=n-1&&i!=s) return 0;
	}
		
	return 1;	
}

bool prime(ll n) {
	for (ll j=2;j*j<=n;j++) if (n%j==0) return 0;
	return 1;
}

int main() {
	boost;
	srand(time(NULL));
	ll n;
	cin >> n;
	while (1) {
		if (isPrime(n)) {
			break;
		}
		n++;
	}
	cout << n << "\n";
	

	return 0;
}