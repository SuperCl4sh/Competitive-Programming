//https://dmoj.ca/problem/nccc8s1
#include <bits/stdc++.h>
using namespace std;
int main() {
	//ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string a,curr,Char;
    cin >> a;
    string b;
    cin >> b;
    set<string>ans;
    for (int i=0;i<a.length();i++) {
	    Char=a[i];
    	for (int j=0;j<b.length();j++) {
		curr=b;
		curr.insert(curr.begin()+j,a[i]);
		ans.insert(curr);
		curr=b;
		curr.insert(curr.end(),a[i]);
		ans.insert(curr);
		curr=b.substr(0,j)+Char+b.substr(j+1,b.length()-j-1);
		ans.insert(curr);
	
	}
	
    }
    for (int i=0;i<b.length();i++) {
	   ans.insert(b.substr(0,i)+b.substr(i+1,b.length()-i-1));
    }
    string now;
    for (auto it=ans.begin();it!=ans.end();++it) {
	now=*it;
	if (now.compare(b)) cout << now << "\n";	
    
    }
    
    return 0;
}

