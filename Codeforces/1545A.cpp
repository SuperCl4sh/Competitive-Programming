#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
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

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);
    #ifdef LOCAL
        freopen("in.in", "r", stdin);
        freopen("out.out", "w", stdout);
    #endif
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<array<int, 3>>ar(N + 1); for (int i = 1; i <= N; i++) cin >> ar[i][0], ar[i][1] = i, ar[i][2] = 0; // 0 is right, 1 is left
        vector<array<int, 2>>copy(N + 1); for (int i = 1; i <= N; i++) for (int j = 0; j < 2; j++) copy[i][j] = ar[i][j];
        sort(1 + all(copy));
        vector<int>inds(N + 1); for (int i = 1; i <= N; i++) inds[copy[i][1]] = i;
        for (int i = 1; i <= N; i++) {
            if (copy[i][1] == i) continue;
            for (int j = 0; j < 3; j++) swap(ar[i][j], ar[copy[i][1]][j]);
            if (abs(i - copy[i][1]) % 2) ar[i][2] ^= 1, ar[copy[i][1]][2] ^= 1;
            swap(copy[i], copy[inds[i]]);
            swap(inds[copy[i][1]], inds[copy[inds[i]][1]]);
        }
        for (int i = 1; i < N; i++) assert(ar[i][0] <= ar[i + 1][0]);
        for (int i = 1; i <= N; i++) assert(copy[i][1] == i);
        bool ok = 1;
        for (int i = 1; i <= N && ok; i++) {
            int tot = 0, nxt = i;
            for (int j = i; j <= N; j++) {
                if (ar[i][0] != ar[j][0]) break;
                if (ar[j][2]) tot += (j % 2) ? 1 : -1;
                nxt = j;
            }
            ok = (tot == 0);
            i = nxt;
        }
        cout << ((ok) ? "YES" : "NO") << nl;
    }
    return 0;
}
