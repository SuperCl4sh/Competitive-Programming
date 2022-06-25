#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define int ll
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define sz(s) (int)s.size()
#define all(a) a.begin(),a.end()
const char nl = '\n';

const int MM = 1e5;
const int BLK = sqrt(MM);

vector<int>planes(MM / BLK + 1, BLK);
bool used[MM + 1];
int32_t main() {
    #ifdef LOCAL
        freopen("in.in", "r", stdin);
        freopen("out.out", "w", stdout);
    #endif
    int G, P; cin >> G >> P;
    int ans = 0;
    for (int i = 0; i < P; i++) {
        int x; cin >> x;
        --x;
        while (x % BLK) {
            if (!used[x]) break;
            x--;
        }
        if (!used[x]) {
            used[x] = 1;
            planes[x / BLK]--;
            ans++;
            continue;
        }
        int blk_ind = x / BLK - 1;
        while (blk_ind >= 0) {
            if (planes[blk_ind]) break;
            blk_ind--;
        }
        if (blk_ind < 0) break;
        for (int j = (blk_ind + 1) * BLK - 1; j >= blk_ind * BLK; j--) {
            if (!used[j]) {
                used[j] = 1;
                planes[blk_ind]--, ans++;
                break;
            }
        }
    }
    cout << ans << nl;
    return 0;
}
