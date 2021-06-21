//https://dmoj.ca/problem/ccc07j1
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int a;
    vector <int> arr;
    for (int i=0;i<3;i++) {
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(),arr.end());
    cout << arr[1]<<endl;
    return 0;
 }
