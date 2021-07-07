#include <bits/stdc++.h>
using namespace std;

/*
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
*/
//^speed


//typedefs
typedef long long ll;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;
typedef long double ld;
typedef pair<ld, ld>pld;
typedef pair<double,double>pdd;
typedef unsigned long long ull;
typedef pair<ld,ld>pld;
typedef pair<str,str>pss;

//defines
#define mp make_pair
#define pb push_back
#define pf push_front
#define PF pop_front
#define PB pop_back
#define P push
#define F first
#define fr front()
#define bk back()
#define S second
#define boost ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);srand(time(NULL))
#define PI 3.14159265
#define sz(s) (int)s.size()
#define sp(x) fixed << setprecision(x)
#define all(a) a.begin(),a.end()
#define mem(ar,a) memset(ar,a,sizeof(ar))
#define MT make_tuple
#define ub upper_bound
#define lb lower_bound
#define FOR(i,a,n,b) for (int i=a;i<n;i+=b)
#define rep(i,a,n) FOR (i,a,n,1)
#define ROF(i,a,n,b) for (int i=a;i>n;i-=b) 
#define vt vector
#define EACH(a,b) for (auto &a: b) 
#define rtn return
#define each(a,b) for (auto a: b)
#define pc putchar
#define gc getchar

//input
template <typename T> void read(T& num) {
	num=0;
	char c;
	while (!(c>47&&c<58)&&c!='-') c=gc();
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
	EACH(a,ar) read(a);

}
template <typename H, typename... Types> void read(H&  num, Types&... num1) {
	read(num);read(num1...);
}

//output
void out(int n) {
	if (n<0) {
		pc('-');
		n*=-1;
		out(n);
		rtn;
	}
	else if (n>9) out(n/10);
	pc(char((n%10)+'0'));
}
void out(ll n) {
	if (n<0) {
		pc('-');
		n*=-1;
		out(n);
		rtn;
	}
	else if (n>9) out(n/10LL);
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
template<typename v, typename... others> void writeln(v s, others... s1) {
	out(s);
	write(s1...);
	pc('\n');
}
template<typename v> void writeln(v s) {
	out(s);
	pc('\n');
}
template<typename v, typename... others> void outln(v s, others... s1) {
	out(s);
	if (sizeof...(s1)) out(' ');
	out(s1...);
	pc('\n');
}
template<typename v> void outln(v s) {
	out(s);
	pc('\n');
}

template <typename T,typename S> ll Pow(T a, S b) {
	ll ret=1;
	while (b) {
		if (b&1) ret*=a;a*=a;b>>=1;
	}
	rtn ret;
}
template <typename T=ll, typename S, typename M> T Pow(T a, S b, M mod) {
	ll ret=1;
	while (b) {
		if (b&1) ret*=a;a=(a*a)%mod;b>>=1;
	}
	rtn ret;
}
void Time(clock_t start) {
	writeln("Process took ",(clock()-start)/double(CLOCKS_PER_SEC)," seconds.");
}

//constants
const int dx8[8]={1,1,-1,-1,2,2,-2,-2},dy8[8]={2,-2,2,-2,1,-1,1,-1},dx4[4]={1,-1,0,0},dy4[4]={0,0,1,-1}; 

clock_t start;
/*--------------------------------------------------------------PROGRAM START-------------------------------------------------------------------------*/

int main() {
	boost;
	
	str S;
	read(S);
	int N=sz(S),ans=0;
	rep (i,0,N) {
		int currAns=0;
		rep (j,0,N-i) {
			if (S[i+j]!=S[i]) break;
			else ++currAns;
		}
		i+=currAns-1;
		ans=max(ans,currAns);
	}
	outln(ans);
	rtn 0;
}




