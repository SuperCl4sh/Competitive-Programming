#include <bits/stdc++.h>
using namespace std;
int possib[5]={-2,-2,-2,-2,-2};
void genes (string a,string b) {
int index=0,v=0;
for (int i=0;i<a.length();i++) {
    for (int j=v;j<v+2;j++) {
        if (islower(b[j]) && islower(a[i])) {
            if (possib[index]==1) {
                possib[index]=2;
            }
            else if (possib[index]==-2){
                possib[index]=0;
            }
    }
    else if (isupper(a[i]) || isupper(b[j])) {
        if (possib[index]==0) {
            possib[index]=2;
        }
        else if (possib[index]==-2){
            possib[index]=1;
        }
    }
    }
    if (i%2==1) {
        index++;
        v+=2;
    }
}
return;
}
void solve (string s) {
for (int i=0;i<s.length();i++) {
    if (isupper(s[i]) && possib[i]>=1){}
    else if (islower(s[i]) && possib[i]!=1) {}
    else {
        cout << "Not their baby!" << endl;
        return;
    }

}
cout << "Possible baby." << endl;
return;

}
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string a,b,s;int n;
    cin >> a >> b;
    genes(a,b);
    cin >> n;
    while (n--) {
        cin >> s;
        solve(s);
    }
    return 0;
 }