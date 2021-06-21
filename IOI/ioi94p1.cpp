//https://dmoj.ca/problem/ioi94p1
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
#define make_tuple MT
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
  
int main() {
	boost;
	int a,n;
	cin >> n;
	vector<vi>ar;
	vi row;
	for (int i=0;i<n;i++) {
		row.clear();
		for (int j=0;j<i+1;j++) {
			cin >> a;
			row.pb(a);
		}
		ar.pb(row);
	}
	int dp[n][n],increase=0,ans=0;
	memset(dp,0,sizeof(dp));
	for (int i=0;i<n;i++) {
		for (int j=0;j<=i;j++) {
			increase=ar[i][j];
			if (i>0) {
				dp[i][j]=max(dp[i][j],dp[i-1][j]);
			if (j>0) {
				dp[i][j]=max(dp[i][j],dp[i-1][j-1]);
			}
			}
			dp[i][j]+=increase;
			ans=max(ans,dp[i][j]);
		}
	}
	cout << ans << "\n";
	
	return 0;
}
