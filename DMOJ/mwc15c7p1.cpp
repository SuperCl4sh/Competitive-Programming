//https://dmoj.ca/problem/mwc15c7p1
#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,diff;
    double r;
    cin >> n;
    double ar[n];
    for (int i=0;i<n;i++) {
    cin >> ar[i];
    }
    for (int i=1;i<n;i++) {
        if (ar[i]==ar[i-1]) {}
        else {
                break;
        }
        if (i==n-1) {
            cout << "both" << endl;
            return 0;
        }
    }
    diff=ar[1]-ar[0];
    for (int i=1;i<n;i++) {
        if (ar[i]-ar[i-1]==diff) {}
        else {
            break;
        }
        if (i==n-1) {
            cout << "arithmetic" << endl;
            return 0;
        }
    }
    if (ar[0]!=0){
        r=ar[1]/ar[0];
        for (int i=1;i<n;i++) {
            if (ar[i-1]*r!=ar[i]) {
                break;
            }
            else if (i==n-1) {
                cout << "geometric" << endl;
                return 0;
            }
        }
    }
    cout << "random" << endl;
    return 0;
 }

