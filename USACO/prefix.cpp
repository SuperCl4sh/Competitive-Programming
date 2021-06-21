/*
ID: 
TASK: prefix
LANG: C++                 
*/

#include <bits/stdc++.h>

#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
using namespace std;
ofstream fout ("prefix.out");
ifstream fin ("prefix.in");
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

vector<str>possib;
str s;
ll ans=0;
bool visited[200005],inQueue[200005];
void solve() {

	priority_queue<int>pq;
	pq.P(0);
	int curr=0;

	while (!pq.empty()) {
		curr=pq.top();
		pq.pop();
		inQueue[curr]=0;
		//cout << sz(pq) << "\n";
		if (visited[curr]) continue;
		if (ans<curr) ans=curr;
		for (int i=0;i<sz(possib);i++) {
			if (curr+sz(possib[i])>sz(s)) continue;
			if (possib[i]==s.substr(curr,sz(possib[i]))&&!visited[curr+sz(possib[i])]&&!inQueue[curr+sz(possib[i])]) {inQueue[curr]=1;pq.P(curr+sz(possib[i]));}
		}
	}

	return;
}

int main() {
	boost;
	while (1) {
		fin >> s;
		if (sz(s)==1&&s[0]=='.') break;
		possib.pb(s);
	}
	str content;
	s="";
	while (getline(fin,content)) {
		s+=content;
	}
	for (int i=0;i<sz(s);i++) {
		if (!isalpha(s[i])) s.erase(s.begin()+i);
	}
	if (s[0]==' ') {
		s=s.substr(1,sz(s)-1);
	}
	solve();	
	fout << ans << "\n";
		
		
	return 0;
}//bfs > dfs
//wasted so much time trying dfs ):

