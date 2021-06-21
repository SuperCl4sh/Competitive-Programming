//https://dmoj.ca/problem/ccc14s2
#include <bits/stdc++.h>
using namespace std;

 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    string names[n][2];
    for (int i=0;i<n;i++) {
        cin >> names[i][0];
    }
    for (int f=0;f<n;f++) {
        cin >> names[f][1];
    }
    for (int a=0;a<n;a++) {
        for (int b=0;b<n;b++) {
            if (names[a][0]==names[a][1] || names[b][0]==names[b][1]) {
                cout << "bad" << endl;
                return 0;
            }
            else if (names[b][0]==names[a][0] || names[b][0]==names[a][1] || names[b][1]==names[a][0] || names[b][1]==names[a][1]) {
                if (names[b][1]==names[a][0] && names[b][0]==names[a][1] || names[b][1]==names[a][1] && names[b][0]==names[a][0]) {}
                else {
                    cout << "bad" << endl;
                    return 0;
                }

            }
        }
    }
    cout << "good" << endl;
    return 0;
 }
