/*
ID: 
TASK: crypt1 
LANG: C++                 
*/
#include <bits/stdc++.h>
#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
using namespace std;
ofstream fout ("crypt1.out");
ifstream fin ("crypt1.in");
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
vi ar;
bool avail[10],good=0;
bool valid(int a) {
	int curr,counter=0;
	while (a>0) {
		counter++;
		curr=a%10;
		if (!avail[curr]) return 0;
		a/=10;
	}
	if (counter>good+3) return 0;
	return 1;
}
int main() {
    boost;
    int a,n;
    fin >> n;
    for (int i=0;i<n;i++) {
	fin >> a;
	avail[a]=1;
    }
    for (int i=0;i<=9;i++) {
    	if (avail[i]) ar.pb(i);
    }
    n=sz(ar);
    int ans=0,curr,curr2,curr3;
    for (int i: ar) {
	    if (i==0) continue;
	    for (int j: ar) {
		    for (int k: ar) {
			    for (int f: ar) {
				    if (f==0) continue;
				    for (int w: ar) {
				    	curr=(100*i+10*j+k)*w;
					curr2=(100*i+10*j+k)*f;
					good=0;
					if (!valid(curr)||!valid(curr2)) continue;
					good=1;
					if (valid(curr+curr2*10)) ++ans;
				    }
				}
			}
		}
	}
    fout << ans << "\n";
    
    return 0;
}

