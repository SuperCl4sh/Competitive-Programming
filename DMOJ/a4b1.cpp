//https://dmoj.ca/problem/a4b1
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b;
    vector <long long> arr;
    cin >> a;
    for (int i=0;i<a;i++) {
        cin >> b;
        arr.push_back(b);
    }
    sort(arr.begin(),arr.end());
    for (int c=0;c<a;c++) {
        cout << arr[c] << endl;
    }
}

