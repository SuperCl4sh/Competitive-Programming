#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int m,n,k;
    cin >> m >> n >> k;
    int rows[m],cols[n];
    memset(rows,0,sizeof(rows));
    memset(cols,0,sizeof(cols));
    char c;int d;
    while (k--) {
    	cin >> c >> d;
	--d;
	if (c=='C') cols[d]++;
	else rows[d]++;
    }
    int ans=0;
    for (int i=0;i<m;i++) {
    	for (int j=0;j<n;j++) {
		if ((rows[i]+cols[j])%2>0) ++ans;
	}
    }
    cout << ans << "\n";
    return 0;
}