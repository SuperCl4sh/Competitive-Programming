//https://dmoj.ca/problem/sac21p5
#include <bits/stdc++.h>
using namespace std;
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
#define fr front
#define bk back
#define S second
#define boost ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);srand(time(NULL))
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
#define rep(i,a,n) FOR (i,a,n,1)
#define vt vector
#define EACH(a,b) for (auto &a: b) 
#define mii map<int,int>
#define rtn return
#define gc getchar
//constants
const ll MOD = 1000000007LL;
const ll MOD2=998244353LL;
const ll high= (ll)(1e15);
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
void read(ld &num) {
	str s="";
	char c;
	while((c=gc())&&(c!=-1&&c!='\n'&&c!='\r'&&c!=' ')) s+=c;
	num=stold(s);
}
void read(double &num) {
	str s="";
	char c;
	while((c=gc())&&(c!=-1&&c!='\n'&&c!='\r'&&c!=' ')) s+=c;
	num=stod(s);
	
}
void read(str &s) {
	s="";
	char c;
	while((c=gc())&&(c!=-1&&c!='\n'&&c!='\r'&&c!=' ')) s+=c;
}
void read(char &a) {
	a=gc();
}
template<typename A, typename B> void read(pair<A,B>a) {
	read(a.F);
	read(a.S);
}
template <typename T> void read(vt<T> &ar) {
	EACH(a,ar) 
		read(a);
}
template <typename T, typename... Types> void read(T&  num, Types&... num1) {
	read(num);read(num1...);
}
template<typename T=ll,typename M=ll, typename S=ll> ll modmul(T a, M b, S m) {ll ans=a*b-m*ll(1.L/m*a*b);return ans+m*(ans<0)-m*(ans>=m);}
template <typename T,typename S> ll Pow(T a, S b) {ll ret=1;while (b) {if (b&1) ret*=a;a*=a;b>>=1;}rtn ret;}
template <typename T=ll, typename S, typename M> T Pow(T a, S b, M mod) {T ans=1;for (; b;a=modmul(a,a,mod),b/=2) {if (b&1) ans=modmul(ans,a,mod);}rtn ans;}
template <typename A, typename B> A rando(A a, B b) { 
	return rand()%(b-a)+a;
}
int dx8[8]={1,1,-1,-1,2,2,-2,-2},dy8[8]={2,-2,2,-2,1,-1,1,-1},dx4[4]={1,-1,0,0},dy4[4]={0,0,1,-1}; 
clock_t start;
/*--------------------------------------------------------------PROGRAM START-------------------------------------------------------------------------*/
int ids[100005],Sizes[100005];
int par(int a) {
	while (a!=ids[ids[ids[ids[a]]]]) {
		ids[a]=ids[ids[ids[ids[a]]]];
		a=ids[a];
	}
	rtn a;
}
void merge(int a, int b) {
	int A=par(a),B=par(b);
	if (A==B) rtn;
	else if (Sizes[A]>Sizes[B]) {
		ids[B]=A;
		Sizes[A]+=Sizes[B];
	}
	else {
		ids[A]=B;
		Sizes[B]+=Sizes[A];
	}
	rtn;
	
}
void init(int n) {
	rep (i,1,n+1) ids[i]=i,Sizes[i]=1;
	rtn;
}
int main() {
	boost;
	int a,b,c,n,q;
	read(n,q);
	init(n);
	while (q--) {
		read(a,b);
		if (a==1) {
			read(c);
			merge(b,c);
		}
		else {
			cout << Sizes[par(ids[b])] << "\n";
		}
	}
	rtn 0;
}

