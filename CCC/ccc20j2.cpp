//https://dmoj.ca/problem/ccc20j2
#include <bits/stdc++.h>
using namespace std;
int main() {
ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int n,p,r,i=1,total ;
cin >> p >> n >> r;
if (p==0) {
    if (n==0) {
        cout << 1 << endl;
        return 0;
    }
    else {
        cout << 0 <<endl;
        return 0;
    }
}
else if (n>p) {
    cout << 0 << endl;
    return 0;
}
if (r==1) {
    cout << p/n << endl;
    return 0;
}
while (true) {
    total=((n*(1-pow(r,i)))/(1-r));
    if (total>p) {
        cout << i-1 << endl;
        return 0;
    }
    i++;
}
return 0;
}

