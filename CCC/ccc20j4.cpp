//https://dmoj.ca/problem/ccc20j4
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
void solve (string t, string s) {
string shift=s,g;int p;
p=t.find(shift);
if (p!=-1) {
    cout << "yes" << endl;
    return;
}
vector<char>ar;
for (int i=0;i<s.length();i++) {
    ar.push_back(s[i]);
}
for (int f=0;f<s.length();f++) {
    ar.push_back(ar[0]);
    ar.erase(ar.begin());
    shift="";
    for (int i=0;i<ar.size();i++) {
        shift+=ar[i];
    }
    p=t.find(shift);
    if (p!=-1) {
        cout << "yes" << endl;
        return;
    }
}
cout << "no" << endl;
return;
}
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string t,s;
    cin >> t >> s;
    solve(t,s);

    return 0;
 }
