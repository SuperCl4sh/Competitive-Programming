#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
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
typedef long long ll;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;
typedef pair<double,double>pdd;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ld,ld>pld;
typedef pair<str,str>pss;
typedef pair<long,long>pl;
char _;
const int MOD = 1000000007;
const ll mxN= (ll)(1e15);
ld dp[301][301][301],n;
ld solve(ld a,ld b, ld c) {
	if (a<0.0||b<0.0||c<0.0) return 0.0;
	if (a==0.0&&b==0.0&&c==0.0) return 1.0;
	else if (dp[int(a)][int(b)][int(c)]!=-1.0) return dp[int(a)][int(b)][int(c)];
	ld A=0.0,B=0.0,C=0.0;
	if (solve(a-1.0,b,c)) A=1.0;
	if (solve(a+1.0,b-1.0,c)) B=1.0;
	if (solve(a,b+1.0,c-1.0)) C=1.0;
	return dp[int(a)][int(b)][int(c)]=((n-a-b-c)+(solve(a-1.0,b,c)+A)*a+(solve(a+1.0,b-1.0,c)+B)*b+(solve(a,b+1.0,c-1.0)+C)*c)/(a+b+c);


}
int main() {
    boost;
    memset(dp,-1,sizeof(dp));
    ld a;
    cin >> n;
    vector<ld>ar={0,0,0};
    for (int i=0;i<int(n);i++) {
	    cin >> a;
	    ar[int(a)-1]++;
    }
    cout << sp(9) << solve(ar[0],ar[1],ar[2])-1.0 << "\n";
    
    return 0;

}
