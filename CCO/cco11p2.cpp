//https://dmoj.ca/problem/cco11p2
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define sz(s) (int)s.size()
#define all(a) a.begin(),a.end()
const char nl = '\n';

const int MM = 1600;
const int SS = 3600;

vector<array<int, 3>>adj[MM + 1];
bool vis[MM + 1][SS + 1];
int32_t main() {
    #ifdef LOCAL
        freopen("in.in", "r", stdin);
        freopen("out.out", "w", stdout);
    #endif
    int S; cin >> S;
    int N, E; cin >> N >> E;
    for (int i = 0; i < E; i++) {
        int u, v, x, a; cin >> u >> v >> x >> a;
        adj[u].pb({v, x * a, x}), adj[v].pb({u, x * a, x});
    }
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>>pq; pq.push({0, 0, 0});
    int ans = -1;
    while (!pq.empty()) {
        int dist = pq.top()[0], sec = pq.top()[1], node = pq.top()[2]; pq.pop();
        if (vis[node][sec]) continue;
        else if (node == N - 1) {
            ans = dist;
            break;
        }
        vis[node][sec] = 1;
        for (auto &X : adj[node]) if (sec + X[1] <= S) pq.push({dist + X[2], sec + X[1], X[0]});
    }
    cout << ans << nl;
    return 0;
}
