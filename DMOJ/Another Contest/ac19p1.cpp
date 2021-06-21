//https://dmoj.ca/problem/ac19p1
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    int t;long long n;long long a;long long b;long long c;
    cin >> t;
    for (int i=0;i<t;i++) {
        cin >> n >> a >> b >> c;
        if (a + b + c<n) {
            cout << -1 << endl;
            continue;
        }
        if (n>=c) {
            n-=c;
        }
        else {
            cout <<"0 0 " << n << endl;
            continue;
        }
        if (n>=b) {
            n-=b;
        }
        else {
            cout << "0 " << n << " " << c << endl;
            continue;
        }
        cout << n << " " << b << " " << c << endl;

    }
    return 0;

}
