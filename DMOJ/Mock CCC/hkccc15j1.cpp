#include <bits/stdc++.h>
using namespace std;

 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,a=0,b=0;string s;
    cin >> n;
    vector <string> ar(n);
    for (int i=0;i<n;i++) {
        cin >> ar[i];
    }
    for (int i=0;i<n;i++) {
        cin >> s;
        if (s==ar[i]) {}
        else if (s=="paper" && ar[i]=="rock") b++;
        else if (s=="rock" && ar[i]=="scissors") b++;
        else if (s=="scissors" && ar[i]=="paper") b++;
        else a++;
    }
    printf("%i %i\n",a,b);
    return 0;
 }