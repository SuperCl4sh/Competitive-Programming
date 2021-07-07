//https://dmoj.ca/problem/set
#include <bits/stdc++.h>
using namespace std;
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int a,n;
    cin >> n;
    set<int>ar;
    for (int i=0;i<n;i++) {
        cin >> a;
        ar.insert(a);
    }
    cout << ar.size() << endl;
    return 0;
 }

