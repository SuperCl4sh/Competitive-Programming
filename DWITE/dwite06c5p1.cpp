//https://dmoj.ca/problem/dwite06c5p1
#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,tot=0;double x,y,a,b,c,d,slope,inter;
    cin >> n;
    vector<pair<double,double>>ar;
    for (int i=0;i<n;i++) {
        cin >> x >> y;
        ar.push_back(make_pair(x,y));
    }
    for (int j=0;j<5;j++) {
        tot=0;
        cin >> a >> b >> c >> d;
        if (c!=a&&d!=b) {
            slope=(d-b)/(c-a);
            inter=d-slope*c;
            for (int g=0;g<ar.size();g++) {
                if (slope*ar[g].first+inter==ar[g].second) tot++;
            }
        }
        else {
            if (b==d) {
                for (int i=0;i<ar.size();i++) {
                    if (ar[i].second==b) tot++;
                }
            }
            else {
                for (int f=0;f<ar.size();f++) {
                    if (ar[f].first==c) tot++;
                }
            }
        }
        cout << tot << endl;
    }
    return 0;
 }

