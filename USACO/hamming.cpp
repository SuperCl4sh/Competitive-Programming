/*
ID: 
TASK: hamming
LANG: C++                 
*/

#include <bits/stdc++.h>

#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
using namespace std;
ofstream fout ("hamming.out");
ifstream fin ("hamming.in");
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
typedef long long ll;
typedef string str;
typedef vector<ll>vll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;
typedef pair<double,double>pdd;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ld,ld>pld;
typedef pair<str,str>pss;
typedef pair<char,char>pcc;
typedef pair<long,long>pl;
typedef pair<bool,bool>pbb;
const ll MOD=998244353LL;
const ll high= (ll)(1e15);
const ll MOD2 = 1000000007LL;
void read(auto &num) {register int Z;num=0;bool negat=0;Z=getchar();if (Z=='-') {negat=1;Z=getchar();}for(;(Z>47&&Z<58);Z=getchar()){num=num*10+Z-48;}if(negat){num*=-1;}}
void Read(auto &num) {register int Z;num=0;bool negat=0;Z=getchar_unlocked();if (Z=='-') {negat=1;Z=getchar_unlocked();}for(;(Z>47&&Z<58);Z=getchar_unlocked()){num=num*10+Z-48;}if(negat){num*=-1;}}
ll modmul(ll a, ll b, ll m) {ll ans=a*b-m*ll(1.L/m*a*b);return ans+m*(ans<0)-m*(ans>=m);}
ll Pow(ll a, ll b, ll mod) {ll ans=1;for (; b;a=modmul(a,a,mod),b/=2) {if (b&1) ans=modmul(ans,a,mod);}return ans;}
void Print(auto &temp) {for (auto x: temp) cout << x << " ";cout << "\n";return;}
int n,b,d;
vector<str>ans;
void solve(str curr,int ind) {
	if (sz(ans)==n) return;
	if (ind==b) {
		for (int i=0;i<sz(ans);i++) {
			int diff=0;
			for (int j=0;j<b;j++) {
				diff+=curr[j]!=ans[i][j];
			}
			if (diff<d) return;
		}
		ans.pb(curr);
		return;
	}
	solve(curr,ind+1);
	curr[ind]='1';
	solve(curr,ind+1);	



	return;
}
int convert(str s) {
	int ret=0;
	for (int i=0,j=sz(s)-1;i<sz(s);i++,j--) {
		if (s[i]=='1') ret+=1<<j;
	}
	return ret;
}
int main() {
	boost;
	fin >> n >> b >> d;
	str start="";
	for (int i=0;i<b;i++) start.append(1u,'0');
	solve(start,0);
	vi finalAns;
	for (int i=0;i<n;i++) {
		finalAns.pb(convert(ans[i]));
	}
	sort(all(finalAns));
	int counter=0;bool last=0;
	for (int i=0;i<sz(finalAns);i++) {
		last=0;
		if (counter==10) {
			fout << "\n";
			fout << finalAns[i];
			if (i+1<sz(finalAns)) fout << " ";
			last=1;
			counter=0;
		}
		else {
			fout << finalAns[i];
			if (i+1<sz(finalAns)&&counter<9) fout << " ";
		}
		++counter;
	}
	if (!last) fout << "\n";
	return 0;
}//this took 11 submissions to AC because of spacing ):

