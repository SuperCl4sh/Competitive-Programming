#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;
typedef long double ld;
typedef unsigned long long ull;
bool isPalin (string s) {
for (int i=0,j=s.length()-1;i<=j;i++,j--) {
    if (s[i]!=s[j]) return 0;
}
return 1;
}
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    str g,s,curr;
    cin >> s;
    for (int i=0;i<s.length();i++) {
        curr=s[i];
        for (int j=i+1;j<s.length();j++) {
            g=s[j];
            curr+=g;
            if (isPalin(curr)) {
                if (curr.length()%2==0) {
                    cout << "Even" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Odd" << endl;
    return 0;
 }