//https://dmoj.ca/problem/ccc09j4
#include <bits/stdc++.h>
//g++ -std=c++14 t.cpp -o f.exe
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
const ll mxN= (ll)(1e15);
const ll MOD2=998244353;
void read(auto &num) {register int Z;num=0;bool negat=0;Z=getchar();if (Z=='-') {negat=1;Z=getchar();}for(;(Z>47&&Z<58);Z=getchar()){num=num*10+Z-48;}if(negat){num*=-1;}}

int main() {

	boost;
	int w;
	read(w);
	vector<str>ar={"WELCOME","TO","CCC","GOOD","LUCK","TODAY"};
	int ind=0,curr;
	vector<str>ans;
	while (ind<sz(ar)) {
		curr=0;
		ans.clear();
		while (ind<sz(ar)) {
			if (curr+sz(ar[ind])+max(0,sz(ans))<=w) {
				curr+=sz(ar[ind]);
				ans.pb(ar[ind]);
				++ind;
			}
			else break;	
		}
		int rem=w-curr;
		while (rem>0) {
			
			for (int i=0;i<max(sz(ans)-1,1)&&rem>0;i++) {
				ans[i].append(1u,'.');
				rem--;
			
			}
		}
		for (int i=0;i<sz(ans);i++) {
			cout << ans[i];
		}	
		cout << "\n";
	}
	return 0;
}
