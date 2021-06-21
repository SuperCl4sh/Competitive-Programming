//https://dmoj.ca/problem/aac1p2
#include <bits/stdc++.h>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	long long n,d,k,x,p;
	cin >> n >> d >> k >> x;
	long long ar[n];
	for (int i=0;i<n;i++) {
		cin >> ar[i];
	}
	cin >> p;
	sort(ar,ar+n,greater<long long>());
	int ind=0;
	
	while (1) {
		while (ar[ind]>=p&&k>0) {
			ar[ind]=ar[ind]*(1.0-(x/100.0));
			--k;
		}
		if (k<0) break;
		++ind;
		if (ind==n) break;
	}
	sort(ar,ar+n,greater<long long>());
	//for (int i=0;i<n;i++) cout << ar[i] << " ";
	
	if (ar[0]<p) cout << "YES\n";
	else cout << "NO\n";

	return 0;
}
