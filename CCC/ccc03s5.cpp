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
char _;
const ll MOD = 1000000007;
const ll mxN= (ll)(1e15);
void read(auto &num) {register int Z;num=0;bool negat=0;Z=getchar();if (Z=='-') {negat=1;Z=getchar();}for(;(Z>47&&Z<58);Z=getchar()){num=num*10+Z-48;}if(negat){num*=-1;}}
int d,aSiz,bSiz,ar[10005],Size[10005],ans=(int)(1e9),counter=0;bool destin[10005];
	vector<pair<int,pii>>adj;
int parent (int a) {
while (a!=ar[a]) {
	ar[a]=ar[ar[a]];
	a=ar[a];
}
return a;

}
void Union(int a, int b) {
aSiz=parent(a);
bSiz=parent(b);
if (Size[aSiz]>Size[bSiz]) {
	ar[aSiz]=ar[bSiz];
	Size[bSiz]+=Size[aSiz];

}
else {
	ar[bSiz]=ar[aSiz];
	Size[aSiz]+=Size[bSiz];
}

return;
}
void construct() {
int a,b,weight;
ans=1e9;
for (int i=0;i<sz(adj);i++) {	
	a=adj[i].S.F;b=adj[i].S.S;weight=adj[i].F;
	if (parent(a)!=parent(b)) {
	Union(a,b);
	ans=min(ans,weight);
	if (destin[a]) {
		destin[a]=0;
		++counter;
	}
	if (destin[b]) {
	destin[b]=0;
	++counter;
	}
	if (counter>=d) break;
}
}
return;
}

int main() {
	boost;	
	int c,r,a,b,w;
	for (int i=0;i<10005;i++) {ar[i]=i;Size[i]=1;}
	cin >> c >> r >> d;
	for (int i=0;i<r;i++) {
	cin >> a >> b >> w;
		adj.pb(mp(w,mp(a,b)));
	}
	sort(adj.begin(),adj.end(),greater<pair<int,pii>>());
	for (int i=0;i<d;i++) {
		cin >> a;
		destin[a]=1;
	}
	construct();
	cout << ans << "\n";
	return 0;
 }