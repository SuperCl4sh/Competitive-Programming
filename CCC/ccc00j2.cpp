//https://dmoj.ca/problem/ccc00j2
#include <bits/stdc++.h>
using namespace std;
int total=0,n,m;string b;
int check (string a) {
b="";
for (int i=a.length()-1;i>=0;i--) {
    if (a[i]=='0') {
        b+="0";
    }
    else if (a[i]=='9') {
        b+="6";
    }
    else if (a[i]=='6') {
        b+="9";
    }
    else if (a[i]=='1') {
        b+="1";
    }
    else if (a[i]=='8') {
        b+="8";
    }
    else {
        return 0;
    }
}
return a==b;
}
void solve (string curr) {
    if (check(curr)==1 && n<=stoi(curr) && m>=stoi(curr)) {
        total++;
    }
    if (stoi(curr)>=m) {
        return;
    }
    solve(curr+"0");
    solve(curr+"1");
    solve(curr+"6");
    solve(curr+"8");
    solve (curr+"9");
return;
}
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    solve("1");
    solve("6");
    solve("8");
    solve("9");
    if (n==0) total++;
    cout << total << endl;
    return 0;
 }

