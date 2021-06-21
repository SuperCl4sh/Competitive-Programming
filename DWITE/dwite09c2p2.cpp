//https://dmoj.ca/problem/dwite09c2p2
#include <bits/stdc++.h>
using namespace std;
 int main() {
     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
     int a,b,counter=0;
     int ar[5];
     for (int j=0;j<5;j++) {
            counter=0;
     for (int i=0;i<5;i++) {
        cin >> a >> b;
        ar[i]=a+b;
     }
     for (int i=0;i<5;i++) {
        cin >> b;
        if (b==ar[i]) {
            counter++;
        }
     }
     cout << counter << endl;
     }
    return 0;
 }
