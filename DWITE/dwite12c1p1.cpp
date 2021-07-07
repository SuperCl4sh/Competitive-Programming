//https://dmoj.ca/problem/dwite12c1p1
#include <bits/stdc++.h>
using namespace std;
 int main() {
     std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int a;string s="*";
    vector <string> b;
    for (int j=0;j<5;j++) {
        cin >> a;
        s="";
    for (int i=1;i<=a;i++) {
            s+="*";
            cout << s << endl;
            if (i<a) {
            b.push_back(s);
            }
    }
    for (int d=a-2;d>=0;d--) {
        cout << b[d]<<endl;
    }
    b.clear();
    }
    return 0;
 }

