/*
ID: 
TASK: sprime
LANG: C++                 
*/
#include <bits/stdc++.h>
#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
using namespace std;
ofstream fout ("sprime.out");
ifstream fin ("sprime.in");
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
const ll MOD = 1000000007;
const ll high= (ll)(1e15);
const ll MOD2 = 998244353;
void read(auto &num) {register int Z;num=0;bool negat=0;Z=getchar();if (Z=='-') {negat=1;Z=getchar();}for(;(Z>47&&Z<58);Z=getchar()){num=num*10+Z-48;}if(negat){num*=-1;}}
void Read(auto &num) {register int Z;num=0;bool negat=0;Z=getchar_unlocked();if (Z=='-') {negat=1;Z=getchar_unlocked();}for(;(Z>47&&Z<58);Z=getchar_unlocked()){num=num*10+Z-48;}if(negat){num*=-1;}}
vi ans;int N;
bool prime(int n) {
	for (int i=2;i<=(int)(sqrt(n));i++) {
		if (n%i==0) return 0;
	}
	return 1;
}
bool valid(int n) {
	while (n>0) {
		if (n==1) return 0;
		if (!prime(n)) return 0;
		n/=10;
	}
	return 1;
}
void solve(int curr, int counter) {
	//fout << curr << "\n";
	if (!valid(curr)) return;
	if (counter==N) ans.pb(curr);
	for (int i=1;i<=9;i+=2) {
		solve(curr*10+i,counter+1);
	}
	return;
}
int main() {
    boost;
    fin >> N;
    for (int i=2;i<=9;i++) solve(i,1);
    sort(all(ans));
    for (int i=0;i<sz(ans);i++) {
	    fout << ans[i] << "\n";
    }
    return 0;
}

