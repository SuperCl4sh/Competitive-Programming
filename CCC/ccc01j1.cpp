//https://dmoj.ca/problem/ccc01j1
#include <bits/stdc++.h>
using namespace std;

 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;string s;
    cin >> n;
    vector <string> ar;
    for (int i=0,j=2*n;i<j;i+=2,j-=2) {
        s="";
        for (int f=0;f<2*n;f++) {
            if (f<=i || f>=j) {
                s+="*";

            }
            else if (f+1>=j) {
                    s+="*";
                }
            else {
                s+=" ";
            }
            if (j-i==2) {
                s="";
                for (int i=0;i<2*n;i++) {
                    cout << "*";
                }
                cout << endl;
                break;
            }
        }
    if (s.length()>0) {
        cout << s << endl;
        ar.push_back(s);
    }
    else {
        break;
    }
    }
    for (int b=ar.size()-1;b>=0;b--) {
        cout << ar[b] << endl;
    }
    return 0;
 }
