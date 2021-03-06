//https://dmoj.ca/problem/sssp
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
#define boost ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
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
char _;
const ll MOD = 1000000007;
const ll high= (ll)(1e15);
const ll MOD2=998244353;
const int mxN=1<<20;
void read(auto &num) {register int Z;num=0;bool negat=0;Z=getchar();if (Z=='-') {negat=1;Z=getchar();}for(;(Z>47&&Z<58);Z=getchar()){num=num*10+Z-48;}if(negat){num*=-1;}}
int n,m;
vector<pair<int,pii>>edges;
void solve() {
int dist[n+1];
for (int i=1;i<=n;i++) dist[i]=mxN;
dist[1]=0;
int weight,target,curr;
for (int i=0;i<n-1;i++) {
	for (int j=0;j<sz(edges);j++) {
		curr=edges[j].S.F;
		target=edges[j].S.S;
		weight=edges[j].F;
		if (dist[curr]!=mxN&&dist[curr]+weight<dist[target]) {
			dist[target]=dist[curr]+weight;
		}
	}
}
for (int i=1;i<=n;i++) {
	if (dist[i]==mxN) cout << -1 << "\n";
	else cout << dist[i] << "\n";
}
return;
}
int main() {
    boost
    int a,b,c;
    cin >> n >> m;
    for (int i=0;i<m;i++) {
    	cin >> a >> b >> c;
	if (i==0) {
		edges.pb(mp(c,mp(a,b)));
		edges.pb(mp(c,mp(b,a)));
		continue;
	}
	else {
		for (int j=0;j<sz(edges);j++) {
			if (edges[j].S.F==a&&edges[j].S.S==b) {
				if (edges[j].F<c) break;
				edges[j].F=c;
				for (int k=0;k<sz(edges);k++) {
					if (edges[k].S.F==b&&edges[k].S.S==a) {
						edges[k].F=c;
						break;
					}
				}
				break;
			}
			if (j==sz(edges)-1) {
				edges.pb(mp(c,mp(a,b)));
				edges.pb(mp(c,mp(b,a)));
			}
			
		}
	}
	
    }
    //cout << "\n";
    for (int i=0;i<sz(edges);i++) {
//	    cout << edges[i].F << " " << edges[i].S.F << " " << edges[i].S.S << "\n";
    }
    solve();
    return 0;
}

