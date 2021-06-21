/*
ID: 
TASK: milk3
LANG: C++                 
*/

#include <bits/stdc++.h>

#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
using namespace std;
ofstream fout ("milk3.out");
ifstream fin ("milk3.in");
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
set<int>ans;
bool visited[21][21][21];
int a,b,c;
void solve(int A, int B, int C) {
	if (A<0||B<0||C<0) return;
	if (visited[A][B][C]) return;
	if (A==0) ans.insert(C);
	visited[A][B][C]=1;

	solve(A,B+min(b-B,C),C-min(b-B,C));
	solve(A+min(a-A,C),B,C-min(a-A,C));
	solve(A,B-min(c-C,B),C+min(B,c-C));
	solve(A+min(a-A,B),B-min(a-A,B),C);
	solve(A-min(b-B,A),B+min(b-B,A),C);
	solve(A-min(c-C,A),B,C+min(c-C,A));
	return;
}

int main() {
    boost;
    fin >> a >> b >> c;
    solve(0,0,c);
    vi Ans;
    for (auto it=ans.begin();it!=ans.end();++it) {
    	Ans.pb(*it);
    }
    for (int i=0;i<sz(Ans);i++) {
	    if (i==sz(Ans)-1) {
	    	fout << Ans[i] << "\n";
	    }
	    else fout << Ans[i] << " ";
    }
    return 0;
}
