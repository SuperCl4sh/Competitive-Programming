//https://dmoj.ca/problem/dmopc20c1p1
#include <bits/stdc++.h>
using namespace std;

 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;string s;
    cin >> n;
    int counter;
    while (n--) {
        counter=0;
        cin >> s;
        for (int i=0;i<s.length();i++) {
            if (s[i]=='M' || s[i]=='C') counter++;
        }
        if (counter==0) cout << "PASS" << endl;
        else if (counter==1) cout << "FAIL" << endl;
        else cout << "NEGATIVE MARKS" << endl;
    }
    return 0;
 }
