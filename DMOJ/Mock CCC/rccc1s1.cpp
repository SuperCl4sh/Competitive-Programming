//https://dmoj.ca/problem/rccc1s1
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,c,v;
	cin >> n >> c >> v;
	string s;		
	cin >> s;
	bool good=1;
	int V=0,C=0;
	char prev;
	for (int i=0;i<s.size();i++) {
		if (s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') {C=0;++V;}
		else if (s[i]!='y') {V=0;C++;}
		else if (s[i]=='y') {++V,++C;}
		if (V>v||C>c) {good=0;break;}
	}
	(good)?printf("YES\n"):printf("NO\n");
	return 0;

}
