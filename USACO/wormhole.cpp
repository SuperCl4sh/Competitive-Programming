/*
ID:
TASK: wormhole
LANG: C++                 
*/

#include <bits/stdc++.h>

#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
using namespace std;
ofstream fout ("wormhole.out");
ifstream fin ("wormhole.in");
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

int Right[13],n,partner[13],ans=0;
vector<pll>coord;

bool check() {
	int a;
	for (int i=0;i<n;i++) {
		a=i;
		for (int j=0;j<n;j++) {
			a=Right[partner[a]];
			if (a==-1) break;
		}	
		if (a!=-1) return 1;
	}
       return 0;	
}

void solve() {
	int i=0;
	bool bad=0;
	for (i=0;i<n;i++) {
		if (partner[i]==-1) {bad=1;break;}
		
	}

	if (!bad) {
		if (check()) ++ans;
		return;
	}
		for (int j=i+1;j<n;j++) {
			if (partner[j]!=-1||i==j) continue;
			partner[i]=j;
			partner[j]=i;
			solve();
			partner[i]=-1;
			partner[j]=-1;
		}
	


	return;
}
int main() {
    boost;
    fin >> n;
    ll x,y;
    for (int i=0;i<n;i++) {
    	fin >> x >> y;
	coord.pb(mp(x,y));
    }
    ll currX,ind;
    mem(Right,-1);
    for (int i=0;i<n;i++) {
	    currX=(ll)(1e12);
	    for (int j=0;j<n;j++) {
		    if (i==j) continue;
		if (coord[j].S==coord[i].S&&coord[j].F>coord[i].F) {
			if (Right[i]==-1) Right[i]=j;
			else if (abs(coord[j].F-coord[i].F)<abs(coord[Right[i]].F-coord[i].F)) Right[i]=j;
		}		    
	    }
	    //cout << Right[i] << " ";
    }
    //cout << "\n";
    mem(partner,-1);
    solve();
    fout << ans << "\n";


    return 0;
}
