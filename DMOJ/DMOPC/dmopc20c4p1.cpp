//https://dmoj.ca/problem/dmopc20c4p1
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll target,n,s;
void solve() {
	ll curr=0,curr2=0;
	if (!(target&1LL)) {
		curr=(target)/2LL-1LL;
		curr2=(target)/2LL+1LL;
		if (curr<0LL||curr2>n) cout << 0LL << "\n";
		else cout << min(curr,n-curr2+1LL) << "\n";
	}
	else {
		curr=(target+1LL)/2LL-1;
		curr2=target-curr;
		if (curr<0LL||curr2>n) cout << 0LL << "\n";
		else cout << min(curr,n-curr2+1) << "\n";
	}
	
	return;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> s;
		target=(n*(n+1LL))/2LL-s;
		solve();
	}
	
	
	return 0;
}
