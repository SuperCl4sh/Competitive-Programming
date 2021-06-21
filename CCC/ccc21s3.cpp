//https://dmoj.ca/problem/ccc21s3
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
const ll MOD = 1000000007;
const ll high= (ll)(1e15);
const ll MOD2 = 998244353;
void read(auto &num) {register int Z;num=0;bool negat=0;Z=getchar();if (Z=='-') {negat=1;Z=getchar();}for(;(Z>47&&Z<58);Z=getchar()){num=num*10+Z-48;}if(negat){num*=-1;}}
void Read(auto &num) {register int Z;num=0;bool negat=0;Z=getchar_unlocked();if (Z=='-') {negat=1;Z=getchar_unlocked();}for(;(Z>47&&Z<58);Z=getchar_unlocked()){num=num*10+Z-48;}if(negat){num*=-1;}}
ll modmul(ll a, ll b, ll m) {ll ans=a*b-m*ll(1.L/m*a*b);return ans+m*(ans<0)-m*(ans>=m);}
ll Pow(ll a, ll b, ll mod) {ll ans=1;for (; b;a=modmul(a,a,mod),b/=2) {if (b&1) ans=modmul(ans,a,mod);}return ans;}
void Print(auto &temp) {for (auto x: temp) cout << x << " ";cout << "\n";return;}

ll n;
vector<pair<ll,pll>>ar;
ll calc(int pos) {
	ll ret=0;
	for (int i=0;i<n;i++) {
		if (abs(ar[i].F-pos)<=ar[i].S.S) continue;
		else {
			if (pos>ar[i].F) {
				ret+=abs(ar[i].F-(pos-ar[i].S.S))*ar[i].S.F;
			}
			else if (pos<ar[i].F) {
				ret+=abs(ar[i].F-(pos+ar[i].S.S))*ar[i].S.F;
			}
		}
	}
	//cout << ret << " " << pos << "\n";
	return ret;

}
int main() {
    boost;
    ll a,b,c,right=0;
    cin >> n;
    for (int i=0;i<n;i++) {
    	cin >> a >> b >> c;
	ar.pb(mp(a,mp(b,c)));
	right=max(a,right);
    }
    sort(all(ar));
    ll left=0,mid=0;
    while (right-left>1) {
	mid=(left+right)/2;
	if (calc(mid)>calc(mid+1)) left=mid;
	else right=mid;
    }
    cout << min(calc(left),calc(right)) << "\n";
    
    return 0;
}
