//https://dmoj.ca/problem/ccc08j2
#include <bits/stdc++.h>
using namespace std;

 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    vector<char>ar={'A','B','C','D','E'};
    int b,n;char c;
    while (true) {
        cin >> b >>n;
        if (b==4 && n==1) {
            break;
        }
        if (b==1) {
            for (int i=0;i<n;i++) {
            c=ar[0];
        ar.erase(ar.begin());
        ar.push_back(c);
            }
        }
        else if (b==2){
            for (int i=0;i<n;i++) {
                c=ar[4];
                ar.erase(ar.end()-1);
                auto it =ar.insert(ar.begin(),c);
            }
        }
        else if (b==3) {
                if (n%2==1) {
                c=ar[0];
                ar[0]=ar[1];
                ar[1]=c;
                }
        }
    }
    for (int i=0;i<5;i++) {
        if (i==4) {
            cout << ar[i] << endl;
        }
        else {
            cout << ar[i] << " ";
        }
    }
    return 0;
 }
