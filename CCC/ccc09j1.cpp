//https://dmoj.ca/problem/ccc09j1
#include <iostream>
using namespace std;
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s= "9780921418";int a,tot=91;
    for (int i=0;i<3;i++) {
        cin >> a;
        if (i==0 || i==2) {
            tot+=a;
        }
        else {
            tot+=3*a;
        }
 }
 printf("The 1-3-sum is %i",tot);

    return 0;
 }
