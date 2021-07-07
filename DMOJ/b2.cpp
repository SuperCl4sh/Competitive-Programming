//https://dmoj.ca/problem/b2
#include <string>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;string num1;string num2;int d;string ans;
    cin >> n;
    for (int a=0;a<n;a++) {
        cin >> num1 >> num2;
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        d= stoi(num1) + stoi(num2);
        ans = to_string(d);
        reverse(ans.begin(),ans.end());
        cout << stoi(ans) << endl;
    }
}

