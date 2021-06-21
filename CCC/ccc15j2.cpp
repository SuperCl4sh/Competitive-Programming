//https://dmoj.ca/problem/ccc15j2
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s,g;
    getline(cin,s);
    int tot=0;bool change=0;
    for (int i=0;i<s.length();i++) {
        if (s[i]==':' && s[i+1]=='-') {
            if (s[i+2]==')') {
                tot++;
                change=1;
            }
            else if (s[i+2]=='(') {
                        tot--;
                        change=1;
                     }
        }
    }
    if (change) {
        if (tot==0) {
            cout << "unsure" << endl;
        }
        else if (tot>0) {
            cout << "happy" << endl;
        }
        else if (tot<0) {
            cout << "sad" << endl;
        }
    }
    else {
        cout << "none" << endl;
    }
    return 0;
 }
