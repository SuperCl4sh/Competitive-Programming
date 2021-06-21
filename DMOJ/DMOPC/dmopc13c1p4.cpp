//https://dmoj.ca/problem/dmopc13c1p4
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
int l,w,startx=0,starty=0;
vector<string>grid;

bool visited[60][60];
void bfs() {
priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>>pq;
pq.P(mp(0,mp(startx,starty)));
int x,y,dist;
for (int i=0;i<60;i++) {
    for (int j=0;j<60;j++) {
        visited[i][j]=0;
    }
}
int ans=INT_MAX;
while (!pq.empty()) {

    dist=pq.top().F;
    x=pq.top().S.F;
    y=pq.top().S.S;
    pq.pop();
    if (y>=l||x>=w||y<0||x<0) continue;
    if (grid[x][y]=='X'||visited[x][y]) continue;
    if (grid[x][y]=='W') {
        ans=min(ans,dist);
    }
    visited[x][y]=1;
    pq.P(mp(dist+1,mp(x+1,y)));
    pq.P(mp(dist+1,mp(x-1,y)));
    pq.P(mp(dist+1,mp(x,y+1)));
    pq.P(mp(dist+1,mp(x,y-1)));
}
(ans>=60)?cout<<"#notworth\n":cout<<ans<<"\n";


}
 int main() {
    boost;
    int t;str s;
    cin >> t;
    for (int i=0;i<t;i++) {
        grid.clear();
        cin >> l >> w;
        for (int i=0;i<w;i++) {
            cin >> s;
            grid.pb(s);
            for (int j=0;j<l;j++) {
                if (s[j]=='C') {
                        startx=i;starty=j;
                }
            }
        }
        bfs();
    }

    return 0;
 }
