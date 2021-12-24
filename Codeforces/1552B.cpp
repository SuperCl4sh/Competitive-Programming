#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sz(a) (int)a.size()
const int MM = (int)5e4;

bool bad[MM + 1];
int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		for (int i = 1; i <= N; i++) bad[i] = 0;
		array<int, 6>ar[N + 1]; for (int i = 1; i <= N; i++) for (int j = 1; j <= 5; j++) cin >> ar[i][j];
		vector<int>perm; for (int i = 1; i <= N; i++) perm.push_back(i);
		shuffle(perm.begin(), perm.end(), rng);
		bool found = 0;
		for (int i = 0; i < N; i++) {
			int curr = perm[i];
			if (bad[curr]) continue;
			vector<int>better;
			for (int j = 1; j <= N; j++) {
				if (curr == j) continue;
				int chk = 0; for (int k = 1; k <= 5; k++) chk += ar[curr][k] < ar[j][k];
				if (chk >= 3) better.push_back(j);
			}
			if (sz(better) == N - 1) {
				cout << curr << '\n';
				found = 1;
			}
			for (auto &x: better) bad[x] = 1;
		}
		if (!found) cout << -1 << '\n';
	}
	return 0;
}