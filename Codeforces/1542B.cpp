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
    //ios::sync_with_stdio(false); cin.tie(0);  
    #ifdef LOCAL
        freopen("in.in", "r", stdin);
        freopen("out.out", "w", stdout);
    #endif
    int T; cin >> T;
    while (T--) {
        int N, A, B; cin >> N >> A >> B;
        if (A == 1) {
            cout << ((N % B == 1 || B == 1 || N == 1) ? "YES" : "NO") << nl;
            continue;
        }
        int curr = 1; bool ok = 0;
        while (curr < N && !ok) {
            if (N % B == curr % B) ok = 1;
            curr *= A;
        }
        cout << ((curr == N || ok) ? "YES" : "NO") << nl;
    }
    return 0;
}
