#include <bits/stdc++.h>

using namespace std;
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    getline(cin,s);
    int i=0,counter=0;
    while (i<s.length()) {
        if (s[i]=='n') {
            counter++;
        }
        i+=4;
    }
    if (s[s.length()-2]=='u') {
        if (counter%2==0) {
            cout << "True" << endl;
        }
        else {
            cout << "False" << endl;
        }
    }
    else {
        if (counter%2==0) {
            cout << "False" << endl;
        }
        else {
            cout << "True" << endl;
        }
    }
    return 0;
 }