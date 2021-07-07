//https://dmoj.ca/problem/ccc17s3
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
void Read(auto &num) {register int Z;num=0;bool negat=0;Z=getchar_unlocked();if (Z=='-') {negat=1;Z=getchar_unlocked();}for(;(Z>47&&Z<58);Z=getchar_unlocked()){num=num*10+Z-48;}if(negat){num*=-1;}}
int counter[2001],tot[4001];
int main() {
	boost;
	int a,n;
	read(n);
	for (int i=0;i<n;i++) {
		read(a);
		counter[a]++;
	}
	for (int i=1;i<=2000;i++) {
		if (!counter[i]) continue; 
		tot[2*i]+=counter[i]/2;
		for (int j=i+1;j<=2000;j++) tot[i+j]+=min(counter[i],counter[j]);
	}
	int ans=0,curr=0;
	for (int i=2;i<=4000;i++) {
		if (!tot[i]) continue;
		if (tot[i]>curr) {
			ans=1;
			curr=tot[i];
		}
		else if (tot[i]==curr) ++ans;
	}
	cout << curr << " " << ans << "\n";
	return 0;
}

