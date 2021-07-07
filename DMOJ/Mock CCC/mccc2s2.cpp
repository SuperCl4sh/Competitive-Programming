//https://dmoj.ca/problem/mccc2s2
#include <bits/stdc++.h>
using namespace std;
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    char a;
    vector <char> s;
    for (int i=0;i<n;i++) {
        cin >> a;
        if (s.size()==0) {
            s.push_back(a);
        }
        else if ((int)a<(int)s[0]) {
            auto it =s.insert(s.begin(),a);
        }
        else if ((int)a==(int)s[0]) {
            auto it = s.insert(s.begin(),a);
        }
        else{
            s.push_back(a);
        }
    }
    for (int i=0;i<n;i++) {
        cout << s[i];
    }
    cout << endl;
    return 0;
 }

