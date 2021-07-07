//https://dmoj.ca/problem/ac20p2
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ar[100005];
int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	ll a,b,n,q;
	cin >> n >> q;
	for (int i=0;i<n;i++) {
		cin >> a;
		ar[a]++;
	}
	while (q--) {
		cin >> a >> b;
		if (a==1) {
			ll start=ar[b];
			ar[b]=0;
			ar[(int)(ceil(((double)(b))/2.0))]+=start;
			ar[(int)(floor(((double)(b))/2.0))]+=start;
		}
		else {
			cout << ar[b] << "\n";
		}
	}
	return 0;
}

