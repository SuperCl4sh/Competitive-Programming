//https://dmoj.ca/problem/ccc21j2
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    string a,ans;int Ans=0,temp;
    for (int i=0;i<n;i++){
	    cin >> a >> temp;
	    if (temp>Ans) {
	    	Ans=temp;
		ans=a;
	    }
    }
    cout << ans << "\n";
    return 0;
}
