#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
*/
//^speed
//typedefs
typedef long long ll;
typedef string str;
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
#define fr front()
#define bk back()
#define boost ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define sz(s) (int)s.size()
#define sp(x) cout << fixed << setprecision(x)
#define all(a) a.begin(),a.end()
#define mem(ar,a) memset(ar,a,sizeof(ar))
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
template <typename T> void read(T& a) {
	cin >> a;
}
template<typename A, typename B> void read(pair<A,B> &a) {
	read(a.F);read(a.S);
}
template <typename A> void read(vt<A>&ar) {
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
template<typename T> void out(vt<T>ar) {
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
template<typename A, typename... types> void write(A s, types... s1) {
	out(s);
	write(s1...);
}
template<typename A, typename... types> void writeln(A s, types... s1) {
	out(s);
	write(s1...,'\n');
}
template<typename A> void writeln(A s) {
	out(s,'\n');
}
template<typename A, typename... types> void outln(A s, types... s1) {
	out(s);
	if (sizeof...(s1)) out(' ');
	out(s1...,'\n');
}
template<typename A> void outln(A s) {
	out(s,'\n');
}

template <typename T,typename A> T Pow(T a, A b) {
	T ret=1;
	while (b) {
		if (b&1) ret*=a;a*=a;b>>=1;
	}
	rtn ret;
}
template <typename T, typename A, typename B> T Pow(T a, A b, B mod) {
	T ret=1;
	while (b) {
		if (b&1) ret=(ret*a)%mod;a=(a*a)%mod;b>>=1;
	}
	assert(ret>=0);
	rtn ret;
}
//constants
const int dx8[8]={1,1,-1,-1,2,2,-2,-2},dy8[8]={2,-2,2,-2,1,-1,1,-1},dx4[4]={1,-1,0,0},dy4[4]={0,0,1,-1}; 
/*--------------------------------------------------------------PROGRAM START-------------------------------------------------------------------------*/
int main() {
	boost;
	int t;
	read(t);
	while (t--) {
		str S,T;
		read(S,T);
		if (sz(T)>sz(S)) {outln("NO");continue;}
		vt<int>inds;
		vt<vt<int>>oddFreq(26),evenFreq(26);
		bool even=0,odd=0;
		rep (i,0,sz(S)) {
			if (S[i]==T[0]) {
				if (!(i&1)&&!even) even=1,inds.pb(i);
				if (i&1&&!odd) odd=1,inds.pb(i);
			}
			if (i&1) oddFreq[S[i]-'a'].pb(i);
			else evenFreq[S[i]-'a'].pb(i);
			
		}
		if (inds.empty()) {outln("NO");continue;}
		bool done=0;
		each(i,inds) {
			int pos,j=0,last=0;
			while (i<sz(S)&&j<sz(T)) {
				if (S[i]==T[j]&&!last) ++i,++j;
				else {
					if (!(i&1)) {
						if (evenFreq[T[j]-'a'].empty()) break;
						pos=upper_bound(all(evenFreq[T[j]-'a']),i)-evenFreq[T[j]-'a'].begin();
						if (pos<sz(evenFreq[T[j]-'a'])&&evenFreq[T[j]-'a'][pos]>i) i=evenFreq[T[j]-'a'][pos];
						else break;
					} 
					else {
						if (oddFreq[T[j]-'a'].empty()) break;
						pos=upper_bound(all(oddFreq[T[j]-'a']),i)-oddFreq[T[j]-'a'].begin();
						if (pos<sz(oddFreq[T[j]-'a'])&&oddFreq[T[j]-'a'][pos]>i) i=oddFreq[T[j]-'a'][pos];
						else break;
					}
				}
			}
			if (j==sz(T)) {
				if (!((sz(S)-i+1)&1)) continue;
			}
			done|=(j==sz(T));
			if (done) break;
		}
		outln((done)?"YES":"NO");
	}	
	rtn 0;
}
