//https://dmoj.ca/problem/ucc21p3
#include <bits/stdc++.h>

using namespace std;
long long diff[10000005];
int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	int n,x,y,r,a,b;
	cin >> n >> x >> y >> r;
	while (r--) {
		cin >> a >> b;
		diff[a]++;
		diff[b+1]--;
	
	}
	long long ans=0,curr=0;
	for (int i=1;i<=(int)(1e7);i++) {
		curr+=diff[i];
		if (i>=x&&i<=y) ans+=curr;
	}
	cout << ans<< "\n";
	
	return 0;
}
