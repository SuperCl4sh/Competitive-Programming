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

int32_t main() {
    #ifdef LOCAL
        freopen("in.in", "r", stdin);
        freopen("out.out", "w", stdout);
    #endif
    int N; cin >> N;
    vector<pii>neg;
    int ans = 0;
    vector<int>ar(N + 1); for (int i = 1; i <= N; i++) {
        cin >> ar[i];
        if (ar[i] < 0LL) neg.pb({ar[i], i});
        else ans++;
        ar[i] = max(ar[i], 0LL);
    }
    sort(all(neg), greater<pii>());
    for (auto &x : neg) {
        int curr = 0;
        ar[x.S] = x.F;
        bool ok = 1;
        for (int i = 1; i <= N && ok; i++) {
            curr += ar[i];
            if (curr < 0) ok = 0;
        }
        ans += ok;
        if (!ok) ar[x.S] = 0;
    }
    cout << ans << nl;
    return 0;
}
