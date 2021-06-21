//https://dmoj.ca/problem/nccc7j4
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string a,b;int tot=0;
    cin >> a >> b;
    int occur[26],occur2[26];
    memset(occur,0,sizeof(occur));
    memset(occur2,0,sizeof(occur2));
    for (int i=0;i<a.length();i++) {
        occur[int(a[i])-65]++;
    }
    for (int j=0;j<b.length();j++) {
        occur2[int(b[j])-65]++;
    }
    for (int i=0;i<26;i++) {
        if (occur[i]>occur2[i]) {
            tot+=occur[i]-occur2[i];
        }
    }
    cout << tot << endl;
    return 0;
 }
