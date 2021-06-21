//https://dmoj.ca/problem/dmopc15c4p4
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
const ll MOD2 = 998244353;
void read(auto &num) {register int Z;num=0;bool negat=0;Z=getchar();if (Z=='-') {negat=1;Z=getchar();}for(;(Z>47&&Z<58);Z=getchar()){num=num*10+Z-48;}if(negat){num*=-1;}}
void Read(auto &num) {register int Z;num=0;bool negat=0;Z=getchar_unlocked();if (Z=='-') {negat=1;Z=getchar_unlocked();}for(;(Z>47&&Z<58);Z=getchar_unlocked()){num=num*10+Z-48;}if(negat){num*=-1;}}

int psa[100005];
vector<vi>freq(2005);
bool exist(int x, int y, int a) {
	if (freq[a].empty()) return 0;
	int left=0,right=sz(freq[a])-1,mid;
	if (freq[a][left]>=x&&freq[a][left]<=y||freq[a][right]>=x&&freq[a][right]<=y) return 1;
	while (right-left>1) {
		mid=(left+right)/2;
		if (freq[a][mid]>=x&&freq[a][mid]<=y) return 1;
		else if (freq[a][mid]>y) right=mid;
		else left=mid;
	}
	if (freq[a][left]>=x&&freq[a][left]<=y) return 1;
	return 0;

}


int main() {
    boost;
    int a,b,c,d,n,k,q;
    cin >> n >> k >> q;
    for (int i=1;i<=n;i++) {
	    cin >> a;
	    freq[a+1000].pb(i);
	    psa[i]=psa[i-1]+a;
    }
    for (int i=0;i<q;i++) {
    	cin >> a >> b >> c>> d;
	if (psa[d]-psa[c-1]<=k) {
		cout << "No\n";
		continue;
	}
	a+=1000;b+=1000;
	if (exist(c,d,a)&exist(c,d,b)) cout << "Yes\n";
	else cout << "No\n";


    } 
    return 0;
}
