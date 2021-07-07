//https://dmoj.ca/problem/gfssoc16j1
#include <bits/stdc++.h>
using namespace std;
int main() {
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
int n,c;
cin >> c >> n;
string d;int ans=0;
int a[4]={0,0,0,0};
for (int i=0;i<c;i++) {
    cin >> d;
    if (d=="TOK") {
        a[0]++;
    }
    else if (d=="English") {
        a[1]++;
    }
    else if (d=="Chemistry") {
        a[2]++;
    }
    else if (d=="Math") {
        a[3]++;
    }
}
for (int i=0;i<4;i++) {
    if (a[i]==0) {
        continue;
    }
    else {
            if (n-i-1<0) {
            cout << "Go to Metro" << "\n" << ans;
            return 0;
        }
        else {while (a[i]-- && n-i-1>=0) {
            ans++;
            n-=i+1;
        }
        }
    }
}
cout << "YEA BOI" << endl;
return 0;
}

