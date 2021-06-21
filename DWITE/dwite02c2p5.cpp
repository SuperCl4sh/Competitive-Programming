//https://dmoj.ca/problem/dwite02c2p5
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;
typedef long double ld;
typedef unsigned long long ull;

 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    str s,ans,alphabet="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    vector<int>freq(26);
    for (int i=0;i<10;i++) {
        getline(cin,s);
        ans="";
        vector<int>freq(26);
        for (int f=0;f<s.length();f++) {
            if (isalpha(s[f])) {

                freq[int(toupper((s[f])))-'A']++;
            }
        }
        for (int j=0;j<26;j++) {
            if (freq[j]>0) {
                ans+=alphabet[j];
                ans+="-";
                ans+=to_string(freq[j]);
                ans+=":";
            }
        }
        if (ans.length()>0) {
        for (int f=0;f<ans.length()-1;f++) {
            cout << ans[f];
        }
        }

        cout << endl;

    }
    return 0;
 }
