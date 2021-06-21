/*
ID:
TASK: combo
LANG: C++                 
*/

#include <bits/stdc++.h>

#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
using namespace std;
ofstream fout ("combo.out");
ifstream fin ("combo.in");
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
vector<vi>good(3);
vector<vi>good2(3);
int Counter=0;
bool solve(int a,int b, int c) {
	bool broken=0;
	for (int i=0;i<sz(good[0]);i++) {
		if (good[0][i]==a) {
			broken=1;
			break;
			
		}
	}
	if (!broken) return 0;
	broken=0;
	for (int i=0;i<sz(good[1]);i++) {
		if (good[1][i]==b) {
			broken=1;
			break;
		}
	}
	if (!broken) return 0;
        broken=0;
	for (int i=0;i<sz(good[2]);i++) {
		if (good[2][i]==c) {
			broken=1;
			break;
		}
	}
	return broken;
}
bool Solve(int a, int b, int c) {
	bool broken=0;
	for (int i=0;i<sz(good2[0]);i++) {
		if (good2[0][i]==a) {
			broken=1;
			break;
			
		}
	}
	if (!broken) return 0;
	broken=0;
	for (int i=0;i<sz(good2[1]);i++) {
		if (good2[1][i]==b) {
			broken=1;
			break;
		}
	}
	if (!broken) return 0;
        broken=0;
	for (int i=0;i<sz(good2[2]);i++) {
		if (good2[2][i]==c) {
			broken=1;
			break;
		}
	}
	return broken;

}

int main() {
    boost;
    int n;
    int ar[3],ar2[3];
    fin >> n;
    for (int i=0;i<3;i++) {
	    fin >> ar[i];
    }
    for (int j=0;j<3;j++) {
	    fin >> ar2[j];
    }
    int counter=0;
    for (int i=0;i<3;i++) {
	counter=0;
	good[i].pb(ar[i]);
	good2[i].pb(ar2[i]);
    	    for (int j=ar[i]-1,f=ar[i]+1,w=ar2[i]-1,k=ar2[i]+1;counter<2;j--,f++,w--,k++) {
		good[i].pb(j);
		good[i].pb(f);
		good2[i].pb(w);
		good2[i].pb(k);
		++counter;
	}
	for (int x=0;x<sz(good[i]);x++) {
		if (good[i][x]<=0) good[i][x]+=n;
		else if (good[i][x]>n) {good[i][x]-=n;}
	}
	for (int x=0;x<sz(good2[i]);x++) {
		if (good2[i][x]<=0) good2[i][x]+=n;
		else if (good2[i][x]>n) {good2[i][x]-=n;}
	}

    }
    int ans=0;
    for (int i=1;i<=n;i++) {
	    for (int j=1;j<=n;j++) {
		    for (int k=1;k<=n;k++) {
	    		if (!solve(i,j,k)&&!Solve(i,j,k)) continue;
		    	ans++;
		    }
	    }
    }
    fout << ans << "\n";
    
    
    
    
    return 0;
}
