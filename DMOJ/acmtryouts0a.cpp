//https://dmoj.ca/problem/acmtryouts0a
#include <string>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;int n;int f; int high;
    cin >> t;
    for (int i=0;i<t;i++) {
        cin >> n;
        high=-1;
        for (int h=0;h<n;h++){
            cin >> f;
            high = max(f,high);

        }
        cout << high << endl;
    }
        return 0;
    }
