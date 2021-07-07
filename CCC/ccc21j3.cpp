//https://dmoj.ca/problem/ccc21j3
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s;int counter;
    while (true) {
    	cin >> s;
	if (s=="99999") break;
    	int sum=(s[0]-'0')+(s[1]-'0');
	if (sum%2==0&&sum>0) counter=1;
	else if (sum%2==1) counter=-1;
	int move=stoi(s.substr(2,s.size()-2));
	if (counter==1) cout << "right ";
	else cout << "left ";
	cout << move << "\n";
    }
    return 0;
}

