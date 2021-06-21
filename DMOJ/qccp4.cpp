//https://dmoj.ca/problem/qccp4
#include <bits/stdc++.h>
using namespace std;
#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
//^speed


//typedefs
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

//defines
#define mp make_pair
#define pb push_back
#define pf push_front
#define PF pop_front
#define PB pop_back
#define P push
#define F first
#define fr front()
#define bk back
#define S second
#define boost ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);srand(time(NULL))
#define PI 3.14159265
#define sz(s) (int)s.size()
#define sp(x) fixed << setprecision(x)
#define all(a) a.begin(),a.end()
#define mem(ar,a) memset(ar,a,sizeof(ar))
#define MT make_tuple
#define upper_bound ub
#define lower_bound lb
#define FOR(i,a,n,b) for (int i=a;i<n;i+=b)
#define rep(i,a,n) FOR (i,a,n,1)
#define ROF(i,a,n,b) for (int i=a;i>n;i-=b) 
#define vt vector
#define EACH(a,b) for (auto &a: b) 
#define mii map<int,int>
#define rtn return
#define gc getchar
#define each(a,b) for (auto a: b)
#define pc putchar

//constants
const ll MOD = 1000000007LL;
const ll MOD2=998244353LL;
const int INF=1<<30;
const int mxN=(int)(1e5);

//input
template <typename T> void read(T& num) {
	num=0;
	register int c;
	c=gc();
	bool isNeg=0;
	if (c=='-') c=gc(),isNeg=1;
	for (;(c>47&&c<58); c=gc()) num=num*10+c-48;
	if (isNeg) num*=-1;

}
void read(str &s) {
	s="";
	char c;
	while((c=gc())&&(c!=-1&&c!='\n'&&c!='\r'&&c!=' ')) s+=c;

}
void read(ld &num) {
	str s="";
	read(s);
	num=stold(s);
}
void read(double &num) {
	str s="";
	read(s);
	num=stod(s);
	
}
void read(char &a) {
	a=gc();
}

template<typename A, typename B> void read(pair<A,B> &a) {
	read(a.F);
	read(a.S);
}
template <typename G> void read(vt<G>&ar) {
	EACH(a,ar) 
		read(a);

}
template <typename H, typename... Types> void read(H&  num, Types&... num1) {
	read(num);
	read(num1...);
}

//output
void out(int n) {
	if (n>9) out(n/10);
	pc(char((n%10)+'0'));
}

void out(ll n) {
	if (n>9) out(n/10LL);
	pc(char((n%10)+'0'));
}
void out(char c) {
	pc(c);
}
void out(str s) {
	rep(i,0,sz(s)) pc(s[i]);
}
void out (ld a) {
	str s=to_string(a);
	out(s);
}

void out(double a) {
	str s=to_string(a);
	out(s);
}
void out (const char *s) {
	
	rep (i,0,strlen(s)) {
		out(s[i]);
	}
}

template<typename T,typename M> void out(pair<T,M>a) {
	out(a.F);
	pc(' ');
	out(a.S);
}
template<typename T> void out(vt<T>ar) {
	rep (i,0,sz(ar)) {
		out(ar[i]);
		if (i+1<sz(ar)) pc(' ');

	}
}

template <typename h, typename... types> void out(h s, types... s1) {
	out(s);
	if (sizeof...(s1)) pc(' ');
	out(s1...);
}
void write() {}
template<typename v, typename... others> void write(v s, others... s1) {
	out(s);
	write(s1...);
}

template <typename T,typename S> ll Pow(T a, S b) {
	ll ret=1;
	while (b) {
		if (b&1) ret*=a;a*=a;b>>=1;
	}
	rtn ret;
}
template <typename T=ll, typename S, typename M> T Pow(T a, S b, M mod) {
	T ans=1;
	for (; b;a=(a*a)%mod,b/=2) {
		if (b&1) ans=(ans*a)%mod;
	}
	rtn ans;
}
template <typename A, typename B> A rando(A a, B b) { 
	return rand()%(b-a)+a;
}

void Time(clock_t start) {
	write("Process took ",(clock()-start)/double(CLOCKS_PER_SEC)," seconds.\n");
}


int dx8[8]={1,1,-1,-1,2,2,-2,-2},dy8[8]={2,-2,2,-2,1,-1,1,-1},dx4[4]={1,-1,0,0},dy4[4]={0,0,1,-1}; 
clock_t start;
/*--------------------------------------------------------------PROGRAM START-------------------------------------------------------------------------*/
vt<vt<int>>ar;
int n;

void rotate(int a, int b, int c, int d) {
	int x1=a,y1=b,x2=a,y2=d,x3=c,y3=d,x4=c,y4=b;
	while (x4!=a) {
		swap(ar[x1][y1],ar[x2][y2]);
		swap(ar[x1][y1],ar[x3][y3]);
		swap(ar[x1][y1],ar[x4][y4]);
		++y1,x2++,y3--,x4--;
	}
	if (a+1==c||b+1==d||a==c||b==d) rtn;

	
	rotate(a+1,b+1,c-1,d-1);
}

int main() {


	read(n);
	vt<int>row(n);
	rep (i,0,n) {
		read(row);
		ar.pb(row);
	}
	map<int,int>go;
	go[90]=1,go[180]=2,go[270]=3,go[0]=0;
	int a,b,c,d,e,q;
	read(q);
	while (q--) {
		read(a,b,c,d,e),--a,--b,--c,--d;
		if (e<0) e+=360;
		e%=360;
		rep (_,0,go[e])
			rotate(a,b,c,d);
		
		
	}
	rep (i,0,n) {
		out(ar[i],'\n');
	}
	


	rtn 0;
}
