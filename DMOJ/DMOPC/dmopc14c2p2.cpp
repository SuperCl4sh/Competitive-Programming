#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
void solve (string log) {
vector<string>pieces;
int tot=0;string curr="";
for (int i=0;i<log.length();i++) {
    if (log[i]=='X') {
        if (curr.length()>0) {
            pieces.push_back(curr);
            tot++;
        }

        curr="";
    }
    else {
        curr+='O';
    }
}
if (curr.length()) {
    pieces.push_back(curr);
    tot++;
}
cout << tot << endl;
if (tot>0) {
for (int i=0;i<pieces.size();i++) {
    if (i+1<pieces.size()) {
        cout << pieces[i] << endl;
    }
    else {
        cout << pieces[i];
    }
}
}
return;
}
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;string log;
    cin >> n >> log;
    solve(log);

    return 0;
 }