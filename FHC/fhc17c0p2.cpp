//https://dmoj.ca/problem/fhc17c0p2
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
const int mxN=4*(int)(1e2);
void read(auto &num) {register int Z;num=0;bool negat=0;Z=getchar();if (Z=='-') {negat=1;Z=getchar();}for(;(Z>47&&Z<58);Z=getchar()){num=num*10+Z-48;}if(negat){num*=-1;}}
void solve() {
	int n;
	cin >> n;
	int ar[n];
	for (int i=0;i<n;i++) {
		cin >> ar[i];
	}
	sort(ar,ar+n,greater<int>());
	int ans=0,start=n;
	for (int i=0;i<start;i++) {
		if (ar[i]>=50) {++ans;continue;}
		else if (i!=start){
			for (int j=start-1;j>i;j--) {
				if (ar[i]*(start-j+1)>=50) {
					start=j;++ans;
					break;
				}
				if (j-1==i) {cout<<ans<<"\n";return;}
			}
			
		}
		
	}
	cout << ans << "\n";
	
	return;
}
int main() {
    boost
    int t,n,w;
    cin >> t;
    for (int i=1;i<=t;i++) {
    	cout << "Case #" << i << ": ";
	solve();
    }
    return 0;
}

