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
#define FOR(i,n) for (int i=0;i<n;i++) 
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

ll tree[100005],tree2[100005],freq[100005],n;
vll ar(1);

ll add(ll ind) {
	ll ret=0;
	while (ind>0) {
		ret+=tree[ind];
		ind-=ind&(-ind);
	}
	return ret;

}

void update(ll ind, ll val) {

	
	while (ind<=n) {
		tree[ind]+=val;
		ind+=ind&(-ind);
	}
	return;

} 

void construct() {
	for (int i=1;i<=n;i++) {
		tree[i]=ar[i];
	}
	for (int i=1;i<=n;i++) {
		int p=i+(i&(-i));
		if (p<=n) tree[p]+=tree[i];
	}
	return;
}
void update2(ll ind,ll val) {
	while (ind<=100000) {
		tree2[ind]+=val;
		ind+=ind&(-ind);
	}
	return;
}
ll add2(ll ind) {
	ll ret=0;
	while (ind>0) {
		ret+=tree2[ind];
		ind-=ind&(-ind);
	}
	return ret;
}
void construct2() {
	for (int i=1;i<=100000;i++) {
		tree2[i]=freq[i];
	}
	for (int i=1;i<=100000;i++) {
		int p=i+(i&(-i));
		if (p<=100000) tree2[p]+=tree2[i];
	}


	return;
}
int main() {
	boost;

	ll a,b,m;
	cin >> n >> m;
	for (int i=1;i<=n;i++) {
		cin >> a;
		ar.pb(a);
		freq[a]++;
	}
	construct();
	construct2();
	char c;
	int left=1,right=n,mid;
	while (m--) {
		cin >> c;
		if (c=='C') {
			cin >> a >> b;
			freq[ar[a]]--,freq[b]++;
			update2(ar[a],-1);
			update2(b,1);
			update(a,b-ar[a]);
			ar[a]=b;

		}
		else if (c=='S') {
			cin >> a >> b;
			cout << add(b)-add(a-1) << "\n";
		}
		else {
			cin >> a;
			cout << add2(a) << "\n";
				
		}


	}



	return 0;
}