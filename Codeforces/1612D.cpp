#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
	int T; cin >> T;
	while (T--) {
		int A, B, X; cin >> A >> B >> X;
		if (X > max(A, B)) {
			cout << "NO" << '\n';
			continue;
		}
		if (B > A) swap(A, B);
		bool found = (A == X || B == X);
		while ((A && B) && !found) {
			if (B > A) swap(A, B);
			if (A % B == X % B && X < max(A, B) || A == X || B == X) found = 1;
			else {
				A %= B;
			}
		}
		cout << ((found) ? "YES" : "NO") << '\n';
	}
	return 0;
}
