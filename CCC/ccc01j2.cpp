//https://dmoj.ca/problem/ccc01j2
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {

    int x,m;
    cin >> x >> m;
    for (int n=1;n<m;n++) {
        if ((x*n)%m==1) {
            cout << n << endl;
            return 0;
        }

    }
    cout << "No such integer exists." << endl;
    return 0;
}
