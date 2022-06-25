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
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const char nl = '\n';

const int MM = (int)1e5;
vector<int>ar(MM + 1);
int N;
struct MinSegmentTree {
    pii combine(pii A, pii B) {
        if (A.F == B.F) return {A.F, A.S + B.S};
        return (A.F > B.F) ? B : A;
    }
    void build() {
        for (int i = 0; i < N; i++) t[i + N] = {ar[i], 1};
        for (int i = N - 1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
    }
    void modify(int p, int value) {  
        for (t[p += N] = {value, 1}; p > 1; p >>= 1) t[p>>1] = combine(t[p], t[p^1]);
    }
    pii query(int l, int r) {
        pii res = {INT_MAX, 1};
        for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
            if (l&1) res = combine(res, t[l++]);
            if (r&1) res = combine(res, t[--r]);
        }
        return res;
    }
    pii t[2 * MM];
};
struct GCDSegmentTree {
    void build() {
        for (int i = 0; i < N; i++) t[i + N] = ar[i];
        for (int i = N - 1; i > 0; --i) t[i] = __gcd(t[i<<1], t[i<<1|1]);
    }
    void modify(int p, int value) {  
        for (t[p += N] = value; p > 1; p >>= 1) t[p>>1] = __gcd(t[p], t[p^1]);
    }
    int query(int l, int r) {
        int res = ar[l];
        for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
            if (l&1) res = __gcd(res, t[l++]);
            if (r&1) res = __gcd(res, t[--r]);
        }
        return res;
    }
    int t[2 * MM];
};
int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);  
    #ifdef LOCAL
        freopen("in.in", "r", stdin);
        freopen("out.out", "w", stdout);
    #endif
    char skip;
    int M; cin >> N >> M;
    ar.resize(N); for (auto &x : ar) cin >> x;
    MinSegmentTree A;
    GCDSegmentTree B;
    A.build(), B.build();
    while (M--) {
        char c; int l, r; cin >> c >> l >> r;
        if (c == 'C') {
            --l;
            A.modify(l, r), B.modify(l, r);
            ar[l] = r;
        }
        else if (c == 'M') {
            --l, --r;
            cout << A.query(l, r + 1).F << nl;
        }
        else if (c == 'G') {
            --l ,--r;
            cout << B.query(l, r + 1) << nl;
        }
        else if (c == 'Q') {
            --l, --r;
            auto PAIR = A.query(l, r + 1);
            int GCD = B.query(l, r + 1);
            cout << ((GCD == PAIR.F) ? PAIR.S : 0) << nl;
        }
    }
    return 0;
}
