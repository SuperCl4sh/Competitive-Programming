//https://dmoj.ca/problem/mccc2s1
#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    int ar[n];
    for (int i=0;i<n;i++) {
        cin >> ar[i];
    }
    sort(ar,ar+n);
    for (int i=0;i<n;i++) {
        if (i+1<n) {
        cout << ar[i] << " ";
        }
        else {
            cout << ar[i] << endl;
        }
    }
    return 0;
 }
