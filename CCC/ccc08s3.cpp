//https://dmoj.ca/problem/ccc08s3
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
char _;
int r,c;
vector<str>grid;
bool visited[25][25];
void bfs() {
    for (int i=0;i<25;i++) {
        for (int j=0;j<25;j++) {
            visited[i][j]=0;
        }
    }
    int ans=INT_MAX;
    priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>>pq;
    pq.P(mp(1,mp(0,0)));
    int dist,x,y;
    while (!pq.empty()) {
        dist=pq.top().F;
        x=pq.top().S.F;
        y=pq.top().S.S;
        pq.pop();
        if (x<0||y<0||x>=r||y>=c) continue;
        if (visited[x][y]||grid[x][y]=='*') continue;
        if (x==r-1&&y==c-1) {
            cout << dist << "\n";
            return;
        }

        visited[x][y]=1;
        if (grid[x][y]=='+') {
            pq.P(mp(dist+1,mp(x+1,y)));
            pq.P(mp(dist+1,mp(x-1,y)));
            pq.P(mp(dist+1,mp(x,y-1)));
            pq.P(mp(dist+1,mp(x,y+1)));
        }
        else if (grid[x][y]=='-') {
            pq.P(mp(dist+1,mp(x,y+1)));
            pq.P(mp(dist+1,mp(x,y-1)));
        }
        else if (grid[x][y]=='|') {
            pq.P(mp(dist+1,mp(x+1,y)));
            pq.P(mp(dist+1,mp(x-1,y)));
        }
    }
    cout <<-1<<"\n";
    return;
}
 int main() {
    boost;
    int t;str s;
    cin >> t;
    while (t--) {
        grid.clear();
        cin >> r >> c;
        for (int i=0;i<r;i++) {
            cin >> s;
            grid.pb(s);
        }
        bfs();
    }
    return 0;
 }
