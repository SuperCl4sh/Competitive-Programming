#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define pf push_front
#define PF pop_front
#define PB pop_back
#define P push
#define F first
#define S second
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define make_tuple MT
#define PI 3.14159265
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
vector<pii>ar;
int ans=0;
int solve(int n,int w) {
	int res=0;
	if (n<0||w==0) return 0;
	if (ar[n].F>w) res=solve(n-1,w);
       	else {
		int tot=ar[n].S+solve(n-1,w-ar[n].F);
		int tot2=solve(n-1,w);
		res=max(tot,tot2);
	}
	return res;

}  
int main() {
    boost;
    int a,b,n,w;
    cin >> n >> w;
    for (int i=0;i<n;i++) {
    	cin >> a >> b;
	ar.pb(mp(a,b));
    }
    cout << solve(n-1,w) << "\n";
    
    return 0;
 }
//weak testcases again which means that this exponential time program suffices for AC verdict :)
