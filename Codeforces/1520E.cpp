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
#define P push
#define F first
#define S second
#define boost ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define sz(s) (int)s.size()
#define sp(x) cout << fixed << setprecision(x)
#define all(a) a.begin(),a.end()
#define FOR(i,a,n,b) for (int i=a;i<n;i+=b)
#define rep(i,a,n) FOR (i,a,n,1)
#define ROF(i,a,n,b) for (int i=a;i>n;i-=b) 
#define EACH(a,b) for (auto &a: b) 
#define each(a,b) for (auto a: b)
//input
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
template<typename T>void out(T a) {
	cout << a;
}
void out(const char *s) {
	rep (i,0,strlen(s)) {
		out(s[i]);
	}
}
template<typename A,typename B> void out(pair<A,B>a) {
	out(a.F);
	out(' ');
	out(a.S);
}
template<typename T> void out(vector<T>ar) {
	rep (i,0,sz(ar)) {
		out(ar[i]);
		if (i+1<sz(ar)) cout << ' ';

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
	out(s);
	write(s1...);
}
template<typename A, typename... types> void writeln(A s, types... s1) {
	out(s);
	write(s1...,'\n');
}
template<typename A> void writeln(A s) {
	write(s,'\n');
}
template<typename A> void outln(A s) {
	out(s);
	out('\n');
}
template<typename A, typename... types> void outln(A s, types... s1) {
	out(s);
	if (sizeof...(s1)) out(' ');
	out(s1...);
	out('\n');
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
vector<int>freq;
const ll INF=1LL<<60;
int main() {
	boost;
	int T;read(T);
	auto check=[&](const string S, int currInd) {
		if (currInd+sz(freq)-1>=sz(S)) return INF;
		ll ret=0;
		rep (i,0,sz(freq)) {
			int newInd=currInd+i;
			ret+=abs(freq[i]-newInd);
		}
		return ret;
	};
	while (T--) {
		int N;read(N);
		string S;read(S);
		freq.clear();
		rep (i,0,N) if (S[i]=='*') freq.pb(i);
		ll ans=check(S,0);
		int l=0,r=sz(S)-sz(freq)+1,m;
		while (r-l>1) {
			m=l+r>>1;
			ll go=check(S,m),go2=check(S,m+1);
			if (go>go2) l=m;
			else r=m;
			ans=min(ans,min(go,go2));
		}
		outln(ans);
	}
	return 0;
}
