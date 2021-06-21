//https://dmoj.ca/problem/ds2
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
vector<pii>edges;
vi ans;
bool MST[100005];
int n,m,Size[100005],ar[100005];
int find (int a) {
	while (a!=ar[a]) {
		ar[a]=ar[ar[ar[ar[a]]]];
		a=ar[a];
	}
	return a;
}
void Union(int a, int b) {
	int c=find(a);
	int d=find(b);
	if (Size[c]>Size[d]) {
		ar[c]=ar[d];
		Size[d]+=Size[c];
	}
	else {
		ar[d]=ar[c];
		Size[c]+=Size[d];
	}
}
void construct() {
	int a,b,counter=0;
	for (int i=0;i<m;i++) {
		a=edges[i].F;b=edges[i].S;
		if (find(a)!=find(b)) {
			Union(a,b);
			if (!MST[a]) {MST[a]=1;++counter;}
			if (!MST[b]) {MST[b]=1;++counter;}
			ans.pb(i+1);
		}
	}
	if (counter==n&&sz(ans)<n) {
		for (int i=0;i<sz(ans);i++) {
			cout << ans[i] << "\n";
		}
	}
	else {
		cout << "Disconnected Graph\n";
	}



	return;
}
int main() {
    boost;
    int a,b;
    cin >> n >> m;
    for (int i=1;i<=n;i++) {
    	Size[i]=1;ar[i]=i;
    }
    for (int i=0;i<m;i++) {
		cin >> a >> b;
    	edges.pb(mp(a,b));
    }
    construct();
    return 0;

}
