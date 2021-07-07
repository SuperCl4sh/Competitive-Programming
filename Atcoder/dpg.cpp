//https://dmoj.ca/problem/dpg
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
vector<vector<int>>adj(100005);
int ans=0;
bool visited[100005];int dp[100005];
void dfs(int node) {
visited[node]=1;
for (auto x: adj[node]) {
	if (!visited[x]) {
		dfs(x);
	}
	dp[node]=max(dp[node],dp[x]+1);
}
return;
} 
int main() {
    boost;
    int n,m,x,y;
    cin >> n >> m;
    for (int i=0;i<m;i++) {
    	cin >> x >> y;
	adj[x].pb(y);
    }
    memset(visited,0,sizeof(visited));
    memset(dp,0,sizeof(dp));
    for (int i=0;i<=n;i++) {
    	if (adj[i].size()>0) {dfs(i);ans=max(ans,dp[i]);}
    }
    cout << ans << "\n";
    return 0;
}

