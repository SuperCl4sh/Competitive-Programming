//https://dmoj.ca/problem/ccc20j3
#include <bits/stdc++.h>
using namespace std;

 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,a,b;string s,g;
    cin >> n;
    vector <int> x;
    vector<int> y;
    for (int i=0;i<n;i++) {
        cin >> s;
        g="";
        for (int v=0;v<s.length();v++) {
            if (s[v]==',') {
               a=stoi(g);
               g="";
            }
            else {
                g+=s[v];
            }
        }
        b=stoi(g);
        x.push_back(a);
        y.push_back(b);
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    cout << x[0]-1 << "," << y[0]-1 << "\n" << x[n-1]+1<<"," << y[n-1]+1 << endl;
    return 0;
 }
