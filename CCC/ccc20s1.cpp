#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    double a,b,n,highestSpeed=INT_MIN,currSpeed;
    cin >> n;
    vector<pair<double,double>>ar;
    for (int i=0;i<n;i++) {
        cin >> a >> b;
        ar.push_back(make_pair(a,b));
    }
    sort(ar.begin(),ar.end());

    for (int i=1;i<n;i++) {
        currSpeed=(ar[i].second-ar[i-1].second)/(ar[i].first-ar[i-1].first);
        if (currSpeed<0) {
            currSpeed*=-1.0;
        }
        highestSpeed=max(highestSpeed,currSpeed);

    }
    cout << fixed<<setprecision(5)<<highestSpeed << endl;

    return 0;
 }