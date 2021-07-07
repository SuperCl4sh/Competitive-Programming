//https://dmoj.ca/problem/ccc07s2
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define F first
#define S second
typedef long long ll;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;
typedef pair<double,double>pdd;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ld,ld>pld;
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int x,y,z,n,m;
    cin >> n;
    vector<pair<int,pii>>boxes;
    for (int i=0;i<n;i++) {
        cin >> x >> y >> z;
        boxes.pb(mp(x,mp(y,z)));
    }
    int smallest;
    cin >> m;
    for (int i=0;i<m;i++) {
        smallest=INT_MAX;
        cin >> x >> y >> z;
        for (int r=0;r<boxes.size();++r) {
            if (boxes[r].F>=x&&boxes[r].S.F>=z&&boxes[r].S.S>=y||boxes[r].F>=x&&boxes[r].S.F>=y&&boxes[r].S.S>=z||boxes[r].F>=z&&boxes[r].S.F>=y&&boxes[r].S.S>=x||boxes[r].F>=y&&boxes[r].S.F>=x&&boxes[r].S.S>=z||boxes[r].F>=z&&boxes[r].S.F>=x&&boxes[r].S.S>=y||boxes[r].F>=y&&boxes[r].S.F>=z&&boxes[r].S.S>=x) {
                smallest=min(smallest,boxes[r].F*boxes[r].S.F*boxes[r].S.S);
            }
        }
        if (smallest==INT_MAX) cout << "Item does not fit." << endl;
        else cout << smallest << endl;
    }
    return 0;
 }

