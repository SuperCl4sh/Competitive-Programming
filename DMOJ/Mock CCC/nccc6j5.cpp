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
ll freq[1005],n,k,dp[1005][1005];
ll solve (int ind,int counter) {
	if (ind<0) return 0LL;
	else if (counter==k) return 1LL;
	else if (dp[ind][counter]!=-1) return dp[ind][counter];
	ll ans;
	if (freq[ind]==0) {ans=(solve(ind-1,counter))%MOD2;}
	else {
		ans=((solve(ind-1,counter+1)%MOD2)*freq[ind])%MOD2;
		ans%=MOD2;
		ans+=(solve(ind-1,counter))%MOD2;
		ans%=MOD2;
	}
	return dp[ind][counter]=ans;
}
int main() {
    boost;
    ll a;
    cin >> n >> k;
    memset(dp,-1,sizeof(dp));
    memset(freq,0LL,sizeof(freq));
    for (int i=0;i<n;i++) {
	    cin >> a;
	    freq[a]++;
    }
    cout << solve(n,0) << "\n";
    return 0;

}