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
int main() {
    boost;
    ll h,w;
    cin >> h >> w;
    vector<str>grid;
	str s;
	for (int i=0;i<h;i++) {
		cin >> s;
		grid.pb(s);
	}
	ll dp[h+10][w+10];
	memset(dp,0,sizeof(dp));
	dp[0][0]=1LL;
	for (int i=0;i<h;i++) {
		for (int j=0;j<w;j++) {
			if (grid[i][j]=='#') continue;
			if (i>0) {
				dp[i][j]+=dp[i-1][j];
			}
			if (j>0) {
				dp[i][j]+=dp[i][j-1];
			}
			dp[i][j]%=MOD;
		}
	}
	cout << dp[h-1][w-1]%MOD << "\n";
    return 0;

}
