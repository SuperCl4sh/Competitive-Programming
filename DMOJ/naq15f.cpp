#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
bool ar[26];
string rem,alphabet="abcdefghijklmnopqrstuvwxyz";
void solve (string s) {
rem="";
for (int j=0;j<26;j++) {
    ar[j]=0;
}
for (int i=0;i<s.length();i++) {
    if (isalpha(s[i])) {
        ar[int(tolower(s[i]))-'a']=1;
    }
}
for (int f=0;f<26;f++) {
    if (!ar[f]) {
        rem+=alphabet[f];
    }
}
if (!rem.length()) {
    cout << "pangram" << endl;
}
else {
    cout << "missing " << rem << endl;
}
return;

}
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;string s;
    getline(cin,s);
    n=stoi(s);
    while (n--) {
        getline(cin,s);
        solve(s);
    }
    return 0;
 }