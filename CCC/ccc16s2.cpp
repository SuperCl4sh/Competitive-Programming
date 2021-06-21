#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,t,tot=0;
    cin >> t >> n;

    int dmoj[n],pegland[n],ar[2*n];
    for (int i=0;i<n;i++) {
        cin >> dmoj[i];
    }
    for (int f=0;f<n;f++) {
        cin >> pegland[f];
    }
    sort(dmoj,dmoj+n);
    sort(pegland,pegland+n);
    if (t==1) {
        for (int i=0;i<n;i++) {
            tot+=max(dmoj[i],pegland[i]);
        }
    }
    else {
        for (int i=0;i<n;i++) {
            ar[i]=dmoj[i];
            ar[i+n]=pegland[i];
        }

        sort(ar,ar+2*n);
        for (int i=2*n-1;i>n-1;i--) {
            tot+=ar[i];
        }
    }
    cout << tot << endl;
    return 0;
 }