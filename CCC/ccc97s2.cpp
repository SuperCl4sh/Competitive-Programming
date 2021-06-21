//https://dmoj.ca/problem/ccc97s2
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;
typedef long double ld;
typedef unsigned long long ull;
int a;
vector<pii>divide;
void divisors() {
divide.clear();
for (int i=1;i<=sqrt(a);i++) {
    if (a%i==0) {
        if (i*i==a) {
            divide.push_back(make_pair(i,i));
        }
        else {
            divide.push_back(make_pair(i,a/i));
        }
    }
}
return;



}
void solve() {
cin >> a;
divisors();
for (int i=0;i<=divide.size();i++) {
    for (int j=0;j<divide.size();j++) {
        if (i==j) continue;
        if (abs(divide[i].first-divide[i].second)==divide[j].first+divide[j].second) {
            cout << a << " is nasty" << endl;
            return;
        }
    }
}
cout << a << " is not nasty" << endl;


return;
}
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for (int i=0;i<n;i++) {
        solve();
    }
    return 0;
 }
