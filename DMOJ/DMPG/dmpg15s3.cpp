//https://dmoj.ca/problem/dmpg15s3
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
using namespace std;
#define mp make_pair
#define pb push_back
#define pf push_front
#define PF pop_front
#define PB pop_back
#define P push
#define F first
#define S second
#define scann(speed){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}speed=s*f;}
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define make_tuple MT
#define PI 3.14159265
#define len(s) (int)s.length()
#define sz(s) (int)s.size()
#define sp(x) fixed << setprecision(x)
typedef long long ll;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;
typedef pair<double,double>pdd;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ld,ld>pld;
typedef pair<str,str>pss;
typedef pair<char,char>pcc;
typedef pair<long,long>pl;
char _;
const ll MOD = 1000000007;
const ll mxN= (ll)(1e15);
void read(auto &num) {register int Z;num=0;bool negat=0;Z=getchar();if (Z=='-') {negat=1;Z=getchar();}for(;(Z>47&&Z<58);Z=getchar()){num=num*10+Z-48;}if(negat){num*=-1;}}
 int main() {
	 boost;
	 ll a,b,c,n,m,ans=0;
	 cin >> n;
	 ll ar[n+1];
	 for (int i=1;i<=n;i++) {
	 	cin >> ar[i];
		ans+=ar[i];
	 }
	 cin >> m;
	 vector<pll>disturb;
	 for (int i=0;i<m;i++) {
		 cin >> b >> c;
		 disturb.pb(mp(b,c));
		 ans-=c;
	 }
	 for (int k=0;k<m;k++) {
		if (max(ar[disturb[k].F],ar[disturb[k].F+1])>ar[disturb[k].F]+ar[disturb[k].F+1]-disturb[k].S) {
			ans-=min(ar[disturb[k].F],ar[disturb[k].F+1]);
			ans+=disturb[k].S;
		}
	}
	 printf("%lld\n",ans);
	 
	 return 0;
 }

