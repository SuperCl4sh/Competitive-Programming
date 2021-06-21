//https://dmoj.ca/problem/factorial
#include <bits/stdc++.h>
using namespace std;
int main() {
ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int n;
unsigned long long a,b;long long c=pow(2,32);
cin >> n;
for (int i=0;i<n;i++) {
    cin >>a;
    if (a>33) {
        cout << 0 << endl;
    }
    else {
        b=1;
        for (int f=2;f<=a;f++) {
            b*=f;
        }
        cout << b%c << endl;
    }
}
return 0;
}
