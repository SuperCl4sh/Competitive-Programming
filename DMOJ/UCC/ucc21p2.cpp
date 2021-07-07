//https://dmoj.ca/problem/ucc21p2
#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	int n;
	cin >> n;
	int ar[n];
	for (int i=0;i<n;i++) cin >> ar[i];
	int curr=0,highest=0;
	for (int i=0;i<n;i++) {
		curr+=ar[i];
		if (curr&1) curr=0;
		else {
			highest=max(curr,highest);
		}
	}
	cout << highest << "\n";
	
	return 0;
}

