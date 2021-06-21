//https://dmoj.ca/problem/p172ex8
#include <bits/stdc++.h>
using namespace std;

 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int ar[101],index;
    memset(ar,0,sizeof(ar));
    vector <int> ans;
    int n=0;
    int highest=0;
    while (true) {
        cin >> n;
        if (n==-1) {
            break;
        }
        ar[n]++;
    }
    for (int i=1;i<101;i++) {
        if (ar[i]>highest) {
            highest=ar[i];
            index=i;
        }
    }
    for (int i=1;i<101;i++) {
        if (ar[i]==highest) {
            cout << i << endl;
        }
    }
    return 0;
 }
