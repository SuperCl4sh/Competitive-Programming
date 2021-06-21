//https://dmoj.ca/problem/ucc21p1
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	string s;
	cin >> s;
	int ans=0;
	for (int i=0;i<s.size();i++) {
		if (s.substr(i,2)!="25"&&s[i]=='2') ++ans;
	}
	cout << ans << "\n";	
	
	
	
	return 0;
}
