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

const ll MOD = (ll)1e9 + 7;
const int LOG = 32;
const int MN = (int)2e5;
vector<ll>fact(MN + 1), powers(MN + 1), inv(MN + 1);
map<ll, ll>dp;
ll HASH = 1e9;
ll binpow (ll A, ll B, ll C) {
	ll ret = 1;
	while (B) {
		if (B&1) ret = ret * A % C;
		A = A * A % C;
		B >>= 1;
	}
	return ret;
}

ll choose (ll N, ll K) {
		if (N == K) return 1;
		return fact[N] * (inv[K] * inv[N - K] % MOD) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	fact[0] = 1; for (int i = 1; i <= MN; i++) fact[i] = fact[i - 1] * i % MOD;
	powers[0] = 1; for (int i = 1; i <= MN; i++) powers[i] = powers[i - 1] * 2 % MOD;
	for (int i = 0; i <= MN; i++) inv[i] = binpow(fact[i], MOD - 2, MOD);
	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;
		vector<vector<pii>>changes(N + 2);
		for (int i = 0; i < M; i++) {
			int L, R, X; cin >> L >> R >> X;
			changes[L].pb({X, 1});
			changes[R + 1].pb({X, -1});
		}
		ll ar[N + 1];
		int curr[LOG]; memset(curr, 0, sizeof(curr));
		int tot = 0;
		for (int i = 1; i <= N; i++) {
			for (auto x: changes[i]) {
				for (int j = 0; j < LOG; j++) curr[j] += x.S * ((x.F >> j) & 1);
				tot += x.S;
			}
			ll now = 0; for (int j = 0; j < LOG; j++) now += (curr[j] == tot) * (1LL << j);
			ar[i] = now;
		}
		ll ans = 0;
		for (int i = 0; i < LOG; i++) {
			ll bits = 0;
			for (int j = 1; j <= N; j++) {
				bits += (ar[j] >> i) & 1;
			}
			for (ll j = 1; j <= bits; j += 2) ans += ((choose(bits, j) * ((1LL << i) % MOD) % MOD) * powers[N - bits]) % MOD, ans %= MOD; // alternatively, 2^(bits - 1) can be used instead of this for loop
		}
		cout << ans << nl;
	}
	return 0;
}
