//https://dmoj.ca/problem/ccc15j3
#include <bits/stdc++.h>

using namespace std;
string ans = "";
int ar[5],f=0;
int lowest=INT_MAX;
string letter;
char alpha[21] = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z'};
string vowels[5]={"a","e","i","o","u"};
void solve(string s) {
for (int i=0;i<s.length();++i) {
    ans+=s[i];
    if (s[i]!='a'&&s[i]!='e'&&s[i]!='i'&&s[i]!='o'&&s[i]!='u') {
            lowest=INT_MAX;
        ar[0]=abs((int)(s[i])-(int)('a'));
        ar[1]=abs((int)(s[i])-(int)('e'));
        ar[2]=abs((int)(s[i])-(int)('i'));
        ar[3]=abs((int)(s[i])-(int)('o'));
        ar[4]=abs((int)(s[i])-(int)('u'));
        for (int j=0;j<5;j++) {
            if (ar[j]<lowest) {
                lowest=ar[j];
                letter=vowels[j];

            }
        }
        f=0;
        ans+=letter;
        if (s[i]=='z') {
            ans+='z';
        }
        else {
            while (alpha[f]!=(char)(s[i])) {
                f++;
            }
            f++;
            if (alpha[f]=='a'||alpha[f]=='e'||alpha[f]=='i'||alpha[f]=='o'||alpha[f]=='u') {
                f++;
            }
            ans+=alpha[f];
        }

    }
}
return;
}
int main() {
ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
string a;
cin >> a;
solve(a);
cout << ans << endl;

return 0;
}
