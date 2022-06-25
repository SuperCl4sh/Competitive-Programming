#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
//#define int ll
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

const int MM = 2e5;
const int BLK = sqrt(MM);

int blocks[MM / BLK + 10][MM + 1];
int32_t main() {
    #ifdef LOCAL
        freopen("in.in", "r", stdin);
        freopen("out.out", "w", stdout);
    #endif
    auto factor = [&](const int N) {
        vector<int>ret; for (int i = 1; i * i <= N; i++) {
            if (!(N % i)) {
                ret.pb(i);
                if (N / i != i) ret.pb(N / i);
            }
        }
        return ret;
    };
    int N, Q; cin >> N >> Q;
    vector<int>ar(N); for (int i = 0; i < N; i++) {
        cin >> ar[i];
        for (auto &x : factor(ar[i])) blocks[i / BLK][x]++;
    }
    while (Q--) {
        int type; cin >> type;
        if (type == 1) {
            int l, r, x; cin >> l >> r >> x;
            --l, --r;
            int ans = 0;
            if (r - l <= 2 * BLK) {
                for (int i = l; i <= r; i++) ans += !(ar[i] % x);
                cout << ans << nl;
                continue;
            }
            while (l % BLK) ans += !(ar[l] % x), l++;
            while (r % BLK) ans += !(ar[r] % x), r--;
            int left_block = l / BLK, right_block = r / BLK;
            for (int i = left_block; i < right_block; i++) ans += blocks[i][x];
            cout << ans << nl;
        }
        else {
            int u, v; cin >> u >> v;
            --u;
            for (auto &x : factor(ar[u])) blocks[u / BLK][x]--;
            ar[u] = v;
            for (auto &x : factor(ar[u])) blocks[u / BLK][x]++;
        }
    }
    return 0;
}
