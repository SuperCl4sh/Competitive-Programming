/*
ID: 
TASK: ariprog
LANG: C++                 
*/

#include <bits/stdc++.h>

#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
using namespace std;
ofstream fout ("ariprog.out");
ifstream fin ("ariprog.in");
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
bool visited[125005];int calc[125005];

int main() {
    boost;

    int n,m;
    fin >> n >> m;
    for (int i=0;i<=m;i++) {
    	calc[i]=pow(i,2);
    }
    vi pattern;
    for (int i=0;i<=m;i++) {
	    for (int j=0;j<=m;j++) {
	    	visited[calc[i]+calc[j]]=1;
	    }
    }
    int curr;
    bool exist=0;
    for (int i=1;i<=2*pow(m,2)/(n-1);i++) {
	for (int k=0;k+i*n<=125005;k++) {	
		curr=k;
		for (int j=0;j<=n;j++) {
			if (!visited[curr+j*i]) break;
			else if (j==n-1) {
				fout << curr << " " << i << "\n";
				exist=1;
			}
		
		}
	}
    }
    if (!exist) fout << "NONE\n";

    return 0;
}
//4.921 seconds on case 8 :p(5 seconds time limit)
