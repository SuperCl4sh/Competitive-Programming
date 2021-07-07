//https://dmoj.ca/problem/fhc15c1p1
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
typedef long long ll;
typedef string str;
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
const ll MOD2=998244353;
void read(auto &num) {register int Z;num=0;bool negat=0;Z=getchar();if (Z=='-') {negat=1;Z=getchar();}for(;(Z>47&&Z<58);Z=getchar()){num=num*10+Z-48;}if(negat){num*=-1;}}
bool composite[(int)(1e7)+1];
ll dp[(int)(1e7)+1];
void construct() {
	composite[1]=1;
	for (int i=2;i<=(int)(1e7);i++) {
		if (!composite[i]) {
			dp[i]=1;
			for (int j=2*i;j<=(int)(1e7);j+=i) {
				composite[j]=1;dp[j]++;
			}
		}
	}
	return;
}
/*void solve() {
	for (int i=2;i<=(int)(1e7);i++) {
		ll curr=0;
		if (!composite[i]) {dp[i]=1;continue;}
		for (int j=2;j<=(int)(sqrt(i));j++) {
			if (i%j==0) {
				if (!composite[j]) ++curr;
				if (!composite[i/j]) ++curr;
			}		
		}
		if (sqrt(i)==(int)(sqrt(i))) --curr;
		dp[i]=curr;
	}
	return;
}*/
void Solve() {
	ll ans=0;
	int a,b,k;
	cin >> a >> b >> k;
	for (int i=a;i<=b;i++) {
		if (dp[i]==k) ++ans;
	}
	cout << ans << "\n";
	return;
}
int main() {
    boost;
    construct();
    int t,i=1;
    cin >> t; 
    while (t--) {
    	cout << "Case #" << i << ": ";
	Solve();
	++i;
    }
    return 0;
}

