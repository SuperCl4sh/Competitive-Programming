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
const int mod=(int)(1e9)+7;
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
bool visited[10005];vector<vector<int>>adj(10005);int curr,dist;
void bfs(int a,int b) {
	priority_queue<pii,vector<pii>,greater<pii>>pq;
	pq.P(mp(0,a));
	memset(visited,0,sizeof(visited));
	while (!pq.empty()) {
		dist=pq.top().F;
		curr=pq.top().S;
		pq.pop();
		if (curr==b) {
			printf("Yes %i\n",dist-1);
			return;
		}
		if (visited[curr]) continue;
		visited[curr]=1;
		for (int i=0;i<adj[curr].size();i++) {
			pq.P(mp(dist+1,adj[curr][i]));
		}
	
	}
	printf("No\n");
	return;


}
 int main() {
    boost;
    int a,b,n;
    cin >>n;
    for (int i=0;i<n;i++) {
	 cin >> a >> b;
	 adj[a].pb(b);
    }
    while (true) {
	   cin >> a >> b;
	   if (a==0||b==0) break;
	   bfs(a,b);
    }
    return 0;
 }