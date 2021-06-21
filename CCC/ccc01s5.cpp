#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;
typedef long double ld;
typedef unsigned long long ull;
vector<str>a;
vector<str>b;
int m,n;str c,d;bool found=0;
void dfs(vector<int>moves, str first,str second) {
if (found) {
    return;
}
if (first==second&&first.length()>0&&moves.size()<m) {
    found=1;
    cout << moves.size() << endl;
    for (int i=0;i<moves.size();i++) {
        cout << moves[i] << endl;
    }
    return;
}
if (moves.size()>m) {
    return;
}
for (int i=0;i<n;i++) {
    moves.push_back(i+1);
    dfs(moves,first+a[i],second+b[i]);
    moves.erase(moves.begin()+moves.size()-1);
}
return;
}


 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    str s;
    cin >> m >> n;
    for (int i=0;i<n;i++) {
        cin >> s;
        a.push_back(s);
    }
    for (int i=0;i<n;i++) {
        cin >> s;
        b.push_back(s);
    }
    vector<int>moves;
    dfs(moves,"","");
    if (!found) {
        cout << "No solution." << endl;
    }
    return 0;
 }