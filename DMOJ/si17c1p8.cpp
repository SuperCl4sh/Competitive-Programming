//https://dmoj.ca/problem/si17c1p8
#include <vector>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int counter=0;
void calc(int total, vector <int> arr,int i) {
    if (total==0) {
        counter++;
        return;
    }
    for (int a=i;a<arr.size();a++) {
        i=a;
        vector <int> nums=arr;
        nums.erase(nums.begin()+a);
        calc(total-arr[a],nums,i);
    }
    return;
}
int main () {
    int n;int target;int m=0;

    cin >> n >> target;
    vector <int> coins(n);
    vector <int> coinsCopy;
    for (int i=0;i<n;i++) {
        cin >> coins[i];
    }
    coinsCopy=coins;
    calc(target,coinsCopy,m);
    cout << counter << endl;
}
