#include <bits/stdc++.h>
using namespace std;

 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,counter=0;
    cin >> n;
    char a;
    char ar[n];
    for (int i=0;i<n;i++) {
        cin >> ar[i];
    }
    for (int j=0;j<n;j++) {
        cin >> a;
        if (a==ar[j]) counter++;
    }
    cout << counter << endl;


    return 0;
 }