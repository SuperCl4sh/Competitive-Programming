//https://dmoj.ca/problem/ioi98p3
#include <bits/stdc++.h>
#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
using namespace std;
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
int n,c;
vi targetOff,targetOn;
set<vector<bool>>ans;
void solve(vector<bool>ar,int counter,int iteration) {
	
	if (counter>c) return;
	//for (int i=1;i<=n;i++) cout << ar[i];
	//cout << "\n";
	bool good=1;
	for (int i=0;i<sz(targetOff)&&good;i++) {
		if (ar[targetOff[i]]) {good=0;}
	}
	for (int i=0;i<sz(targetOn)&&good;i++) {
		if (!ar[targetOn[i]]) {good=0;}
	}
	if (good) ans.insert(ar);
	
	if (iteration==0) {
		++iteration;
		solve(ar,counter,iteration);
		for (int i=1;i<=n;i++) (ar[i])?ar[i]=0:ar[i]=1;
		solve(ar,counter+1,iteration);
	}
	else if (iteration==1) {
		++iteration;
		solve(ar,counter,iteration);
		for (int i=1;i<=n;i+=2) (ar[i])?ar[i]=0:ar[i]=1;
		solve(ar,counter+1,iteration);
	}
	else if (iteration==2) {
		++iteration;
		solve(ar,counter,iteration);
		for (int i=2;i<=n;i+=2) (ar[i])?ar[i]=0:ar[i]=1;
		solve(ar,counter+1,iteration);
	}
	else if (iteration==3) {
		++iteration;
		solve(ar,counter,iteration);
		for (int i=1;i<=n;i+=3) (ar[i])?ar[i]=0:ar[i]=1;
		solve(ar,counter+1,iteration);
	}
	else return;
	return;
}
int main() {
    boost;
    int a;
    cin >> n >> c;
    vector<bool>ar(n+1,1);
    while (true) {
    	cin >> a;
	if (a==-1) break;
	targetOn.pb(a);
    
    }
    while (true) {
	    cin >> a;
	    if (a==-1) break;
	    targetOff.pb(a);
    }
    solve(ar,0,0);
    vector<bool>curr;
    if (ans.empty()) {
    	cout << "IMPOSSIBLE\n";
	return 0;
    }
    for (auto it=ans.begin();it!=ans.end();++it) {
    	curr=*it;
	for (int i=1;i<sz(curr);i++) {
		cout << curr[i];
	}
	cout << "\n";
    }
    
    
    return 0;
}

