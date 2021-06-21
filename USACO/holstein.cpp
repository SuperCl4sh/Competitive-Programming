/*
ID: 
TASK: holstein
LANG: C++                 
*/

#include <bits/stdc++.h>

#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
using namespace std;
ofstream fout ("holstein.out");
ifstream fin ("holstein.in");
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

vector<vi>feeds;
vi ar;
int v,g;
vi ans;
set<pair<int,vi>>visited;
void solve(vi curr, int ind, vi currAns) {
	if (!ans.empty()&&sz(currAns)>sz(ans)) return;
	pair<int,vi>current=mp(ind,curr);
	if (visited.count(current)!=0) return;
	visited.insert(mp(ind,curr));
	bool valid=1;
	for (int i=0;i<v&&valid;i++) {
		if (ar[i]>curr[i]) valid=0;
	}
	if (valid) {
		if (ans.empty()) {sort(all(currAns));ans=currAns;}
		else if (sz(ans)>sz(currAns)) {
			bool good=1;
			sort(all(currAns));
			for (int i=0;i<sz(ans);i++) {
				if (ans[i]>currAns[i]) break;
				else if (currAns[i]>ans[i]) {good=0;break;}
			}
			if (good) ans=currAns;
		}
		return;
	}
	if (ind>g) return;
	vi start=curr;
	for (int i=ind;i<g;i++) {
		solve(curr,i+1,currAns);
		for (int j=0;j<v;j++) {
			curr[j]+=feeds[i][j];
		}
		currAns.pb(i);
		solve(curr,i+1,currAns);
		curr=start;
		currAns.PB();
	}



	return;
}
int main() {
	boost;
	int a;
	fin >> v;
	vi curr;
	for (int i=0;i<v;i++) {fin>>a;ar.pb(a);}
	fin >> g;
	for (int i=0;i<g;i++) {
		for (int j=0;j<v;j++) {
			fin >> a;
			curr.pb(a);
		}
		feeds.pb(curr);
		curr.clear();	
	}
	vi start(v,0);
	vi New;
	solve(start,0,New);
	fout << sz(ans) << " ";
	for (int i=0;i<sz(ans);i++) {
		if (i+1<sz(ans)) fout << ans[i]+1 << " ";
		else fout << ans[i]+1 << "\n";
	}

    
    return 0;
}

