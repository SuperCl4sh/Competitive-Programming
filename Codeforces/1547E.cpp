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

const int MM = (int)3e5;

int pre[MM], suf[MM];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int Q; cin >> Q;
    while (Q--) {
        int N, K; cin >> N >> K;
        for (int i = 0; i < K; i++) pre[i] = suf[i] = INT_MAX;
        vector<int>A(K); for (auto &x: A) cin >> x;
        vector<int>T(K); for (auto &x: T) cin >> x;
        vector<array<int, 2>>paired; for (int i = 0; i < K; i++) paired.pb({A[i], T[i]});
        sort(all(paired));
        for (int i = 0, j = K - 1; i < K; i++, j--) pre[i] = min(pre[max(0, i - 1)], paired[i][1] - paired[i][0]), suf[j] = min(suf[min(j + 1, K - 1)], paired[j][1] + paired[j][0]);
        vector<int>ans;
        int ptr = 0;
        for (int i = 1; i <= N; i++) {
            while (ptr + 1 < K && paired[ptr][0] < i) ptr++;
            int curr = INT_MAX;
            if (paired[ptr][0] >= i) {
                curr = suf[ptr] - i;
                if (ptr) curr = min(curr, pre[ptr - 1] + i);
            }
            else {
                curr = pre[ptr] + i;
                if (ptr + 1 < K) curr = min(curr, suf[ptr + 1] - i);
            }
            ans.pb(curr);
        }
        for (int i = 0; i < N; i++) cout << ans[i] << " \n"[i == N - 1];
    }
    return 0;
}
