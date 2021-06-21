//https://dmoj.ca/problem/ccc15s1
#include <bits/stdc++.h>
using namespace std;

 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int k,n,total=0;
    cin >> k;
    vector <int> ar;
    for (int i=0;i<k;i++) {
        cin >> n;
        if (n==0 && ar.size()>0) {
            ar.erase(ar.begin()+ar.size()-1,ar.begin()+ar.size());
        }
        else {
            ar.push_back(n);
        }
    }
    for (int i=0;i<ar.size();i++) {
        total+=ar[i];
    }
    cout << total<<endl;
    return 0;
 }
