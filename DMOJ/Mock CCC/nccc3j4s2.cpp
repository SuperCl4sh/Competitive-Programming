#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;
typedef long double ld;
typedef unsigned long long ull;

 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int a,n;
    cin >> n;
    vector<int>medians;
    vector<int>ans;
    for (int i=0;i<n;i++) {
        for (int f=0;f<n;f++) {
            cin >> a;
            medians.push_back(a);
        }
        sort(medians.begin(),medians.end());
        ans.push_back(medians[(int)(n/2)]);
        medians.clear();
    }
    sort(ans.begin(),ans.end());
    cout << ans[(int)(n/2)] << endl;
    return 0;
 }