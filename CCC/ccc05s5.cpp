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
const int MM=(int)(1e5);
map<int,int>ids;
int id=1;
struct ft {
	void upd(int ind, int val) {
		if (!ind) rtn;
		while (ind<=MM) tree[ind]+=val,ind+=ind&(-ind);
	}
	ll sum(int ind) {
		int ret=0;
		while (ind) ret+=tree[ind],ind-=ind&(-ind);
		rtn ret;
	}
	ll query(int l, int r) {
		rtn sum(r)-sum(l-1);
	}
	void init() {
		mem(tree,0);
	}
	int tree[MM+5];
}freq;
int main() {
	boost;
	int T;read(T);
	vt<int>vals(T);read(vals);
	vt<int>valsCopy=vals;
	sort(all(valsCopy));
	rep (i,0,T) {
		if (i) {
			if (valsCopy[i]!=valsCopy[i-1]) ids[valsCopy[i]]=id++;
		}
		else ids[valsCopy[i]]=id++;
	}
	freq.init();
	ll ans=0;
	rep (i,0,T) {
		ans+=freq.query(ids[vals[i]],MM)+1;
		freq.upd(ids[vals[i]]-1,1);
	}
	str tempAns=to_string(ld(ans)/ld(T)),finalAns="";
	int ind=0;
	while (ind<sz(tempAns)) {
		if (tempAns[ind]=='.') {finalAns+=tempAns.substr(ind,3);break;}
		finalAns+=tempAns[ind];
		++ind;
	}
	outln(finalAns);
	rtn 0;
}
