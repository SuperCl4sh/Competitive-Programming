//https://dmoj.ca/problem/ccc03s3
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;
typedef long double ld;
typedef unsigned long long ull;
vector<string>grid;
vector<int>areas;
bool visited[30][30];
int tot=0,r,c;
void dfs(int x, int y) {
if (x>=r||y>=c||x<0||y<0) return;
if (visited[x][y]||grid[x][y]=='I') return;
visited[x][y]=1;
tot++;
dfs(x+1,y);
dfs(x-1,y);
dfs(x,y-1);
dfs(x,y+1);
}
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,room=0;str s;
    cin >> n >> r>> c;
    for (int i=0;i<r;i++) {
            cin >> s;
            grid.push_back(s);
    }
    for (int f=0;f<r;f++) {
        for (int i=0;i<c;i++) {
            if (grid[f][i]=='.'&&!visited[f][i]) {
                tot=0;
                dfs(f,i);
                areas.push_back(tot);
            }
        }
    }
    sort(areas.begin(),areas.end(),greater<int>());
    for (int i=0;i<areas.size();i++) {
        if (n>=areas[i]) {
            room++;
            n-=areas[i];
        }
        else {
            break;
        }
    }
    if (room!=1) {
        cout << room << " rooms";
    }
    else if (room==1) {
        cout << room << " room";
    }
    cout << ", " << n << " square metre(s) left over" << endl;
    return 0;
 }

