//https://dmoj.ca/problem/acc7p1
#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	long long t,n;
	cin >> t;
	while (t--) {
		cin >> n;
		if (n==2) {
			cout << 2 << "\n";
		}
		else cout << n-1 << "\n"; 
	}
	return 0;
}

