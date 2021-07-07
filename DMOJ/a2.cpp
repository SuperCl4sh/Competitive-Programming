//https://dmoj.ca/problem/a2
#include <bits/stdc++.h>
using namespace std;
void solve (string s) {
if (s[0]=='p' && s[1]=='q' || s[0]=='q' && s[1]=='p') {
    cout << "Mirrored pair" << endl;
}
else if (s[0]=='d' && s[1]=='b' || s[0]=='b' && s[1]=='d') {
    cout << "Mirrored pair" << endl;
}
else {
    cout << "Ordinary pair" << endl;
}
return;
}
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    cout << "Ready" << endl;
    while (true) {
        getline(cin,s);
        if (s=="  ") break;
        solve(s);
    }
    return 0;
 }

