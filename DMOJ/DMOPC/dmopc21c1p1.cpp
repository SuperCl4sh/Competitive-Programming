#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define sz(s) (int)s.size()
#define all(a) a.begin(),a.end()
const char nl = '\n';

int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	int N;cin >> N;
	vector<ll>ar(N);for (auto &x: ar) cin >> x;
	ll odd=0,even=0;
	for (int i=0;i<N;i++) {
		if (ar[i]&1) {
			odd+=(ar[i]+1)/2;
		}
		else {
			even+=ar[i]/2;
		}
	}
	if (even>odd) cout << "Duke" << nl;
	else cout << "Alice" << nl;
	return 0;
}
