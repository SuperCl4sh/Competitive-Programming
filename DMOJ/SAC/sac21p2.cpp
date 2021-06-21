//https://dmoj.ca/problem/sac21p2
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,k;
	cin >> n >> k;
	long long ar[n];
	for (int i=0;i<n;i++) cin >> ar[i];
	sort(ar,ar+n,greater<long long>());
	long long ans=0;
	for (int i=0;i<min(k,n);i++) ans+=ar[i];
	cout << ans << "\n";


	return 0;
}
