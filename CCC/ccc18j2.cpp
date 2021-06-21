#include <bits/stdc++.h>
using namespace std;

 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,counter=0;
    cin >> n;
    string a,b;
    cin >> a >> b;
    for (int i=0;i<n;i++) {
        if (a[i]==b[i] && a[i]=='C') counter++;
    }
    cout << counter << endl;
    return 0;
 }