//https://dmoj.ca/problem/vmss7wc15c6p3
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
typedef long long ll;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;
typedef pair<double,double>pdd;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ld,ld>pld;
typedef pair<str,str>pss;
char _;
const int MOD=1e9+7;

int n,ans=INT_MIN;
vector<int>total(1);
vector<vector<int>>adj(400050);
int dfs(int ind) {
int tot=total[ind];
for (int i=0;i<adj[ind].size();i++) {
    tot+=dfs(adj[ind][i]);
}
ans=max(ans,tot);
return tot;
}
 int main() {
    boost;
    cin >> n;
    int a,b;
    for (int i=0;i<n-1;i++) {
        cin >> a >> b;
        adj[a].pb(b);
    }
    for (int i=0;i<n;i++) {
        cin >> a;
        total.pb(a);
    }
    dfs(1);
    cout << ans << "\n";
    return 0;
 }
