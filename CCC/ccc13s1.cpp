//https://dmoj.ca/problem/ccc13s1
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
using namespace std;
bool checker(int num) {
    string toString = to_string(num);
    vector <int> arr(10);
    for (int c=0;c<toString.length();c++) {
            if (arr[(int)toString[c]-48]) {
                return false;
            }
            int t= (int)toString[c]-48;
            arr[t]++;
    }
    return true;
}
int main () {
    int y;
    cin >> y;
    y++;
    string yes = "1243";
    while (true) {
            if (checker(y)) {
                break;
            }
            else {
                y++;
            }
    }
    cout << y << endl;
    return 0;
}

