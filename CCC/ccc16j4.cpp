#include <bits/stdc++.h>
using namespace std;
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string a,b,s;int h=-1,m;double tot=0;
    cin >> s;
    for (int i=0;i<s.length();i++) {
        if (s[i]==':') {
            if (h==-1) {
                h=stoi(a);
                a="";
            }
        }
        else {
            a+=s[i];
        }
    }
    m=stoi(a);
    while (tot<120){
        if (h>=7&&h<10 || h>=15&&h<19) {
            tot+=0.5;
        }
        else {
            tot++;
        }
        m++;
        if (m%60==0) {
            h++;
            m=0;
        }
        h%=24;

    }
    a=to_string(h);b=to_string(m);
    if (a.length()==1) {
        cout << "0"<<a;
    }
    else {
        cout << a;
    }
    cout << ':';
    if (b.length()==1) {
        cout << "0"<<b<<endl;
    }
    else {
        cout << b << endl;
    }
    return 0;
 }