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

int N, targ;
vector<int>A;

bool go(int ind) {
    if (ind == N) return 1;
    int curr = 0, best = -1;
    for (int i = ind; i < N; i++) {
        curr ^= A[i];
        if (curr == targ) best = i;
    }
    if (best == -1) return 0;
    return go(best + 1);
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    #ifdef LOCAL
        freopen("in.in", "r", stdin);
        freopen("out.out", "w", stdout);
    #endif
    int T; cin >> T;
    while (T--) {
        cin >> N;
        A.clear(); for (int i = 0; i < N; i++) {
            int X; cin >> X;
            A.pb(X);
        }
        bool ok = 0;
        targ = 0;
        for (int i = 0; i < sz(A) - 1 && !ok; i++) {
            targ ^= A[i];
            if (go(i + 1)) ok = 1;
        }
        cout << ((ok) ? "YES" : "NO") << nl;
    }
    return 0;
}
