#include <bits/stdc++.h>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n;double a;
	cin >> n >> a;
	if (n*n>a*a*3.14) cout << "SQUARE\n";
	else cout << "CIRCLE\n";


	return 0;
}