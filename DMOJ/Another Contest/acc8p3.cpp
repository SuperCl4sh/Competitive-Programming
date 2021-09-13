#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
//typedefs
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
typedef unsigned long long ull;
//defines
#define mp make_pair
#define pb push_back
#define pf push_front
#define PF pop_front
#define PB pop_back
#define F first
#define S second
#define sz(s) (int)s.size()
#define sp(x) cout << fixed << setprecision(x)
#define all(a) a.begin(),a.end()
#define FOR(i,a,n,b) for (int i=a;i<n;i+=b)
#define rep(i,a,n) FOR (i,a,n,1)
#define ROF(i,a,n,b) for (int i=a;i>n;i-=b)
#define EACH(a,b) for (auto &a: b)
#define each(a,b) for (auto a: b)
//input
template <typename A> void read(vector<A>&ar);
template<typename A, typename B> void read(pair<A,B> &a);
template <typename T> void read(T& a) {
	cin >> a;
}
template<typename A, typename B> void read(pair<A,B> &a) {
	read(a.F);read(a.S);
}
template <typename A> void read(vector<A>&ar) {
	EACH(a,ar) read(a);
}
template <typename A, typename... Types> void read(A&  num, Types&... num1) {
	read(num);read(num1...);
}
//output
template<typename T> void out(vector<T>ar);
template<typename A,typename B> void out(pair<A,B>a);
template<typename T>void out(T a) {
	cout << a;
}
void out(const char *s) {
	rep (i,0,strlen(s)) out(s[i]);
}
template<typename A,typename B> void out(pair<A,B>a) {
	out(a.F);out(' ');out(a.S);
}
template<typename T> void out(vector<T>ar) {
	rep (i,0,sz(ar)) {
		out(ar[i]);
		if (i+1<sz(ar)) out(' ');
	}
}
template <typename A, typename... Types> void out(A s, Types... s1) {
	out(s);
	if (sizeof...(s1)) out(' ');
	out(s1...);
}
void write() {}
void writeln() {
	out('\n');
}
void outln() {
	out('\n');
}
template<typename A, typename... types> void write(A s, types... s1) {
	out(s);write(s1...);
}
template<typename A, typename... types> void writeln(A s, types... s1) {
	out(s);write(s1...,'\n');
}
template<typename A> void writeln(A s) {
	write(s,'\n');
}
template<typename A> void outln(A s) {
	out(s);out('\n');
}
template<typename A, typename... types> void outln(A s, types... s1) {
	out(s);
	if (sizeof...(s1)) out(' ');
	out(s1...);out('\n');
}

template <typename T,typename A> T Pow(T a, A b) {
	T ret=1;
	while (b) {
		if (b&1) ret*=a;a*=a;b>>=1;
	}
	assert(ret>=0);
	return ret;
}
template <typename T, typename A, typename B> T Pow(T a, A b, B mod) {
	T ret=1;
	while (b) {
		if (b&1) ret=(ret*a)%mod;a=(a*a)%mod;b>>=1;
	}
	assert(ret>=0);
	return ret;
}
//constants
const int dx8[8]={1,1,-1,-1,2,2,-2,-2},dy8[8]={2,-2,2,-2,1,-1,1,-1},dx4[4]={1,-1,0,0},dy4[4]={0,0,1,-1};
/*--------------------------------------------------------------PROGRAM START-------------------------------------------------------------------------*/
const int mxm=(int)(1e4);
int dp[mxm*mxm+5],psa[mxm*mxm+5];
int dig (ll N) {
	int ret=0;
	do {
		ret++;
		N/=10;
	} while (N);
	return ret;
}
int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int M, Q;read(M, Q);
	int A=1,B=1,ind=1,period=0;
	while (period==0) {
		int tmp=B;
		B+=A;
		B%=M;
		A=tmp;
		if (A==0 && B==1 && ind>1) {
		       period=ind+1;
		}
 		ind++;		
	}
	dp[1]=1,dp[2]=1;
	psa[1]=1,psa[2]=2;
	rep (i,3,period+1) {
		dp[i]=(dp[i-1]+dp[i-2])%M;
		psa[i]=psa[i-1]+dig(dp[i]);
	}
	string concat=".";
	rep (i,1,period+1) {
		concat+=to_string(dp[i]);
	}
	rep (i,1,Q+1) {
		ll N;read(N);
		N%=ll(psa[period]);
		if (N==0) {
			outln(to_string(dp[period])[dig(dp[period])-1]);
			continue;
		}
		outln(concat[N]);
	}
	return 0;
}
