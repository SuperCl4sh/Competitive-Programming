//https://dmoj.ca/problem/ccc03s1
#include <bits/stdc++.h>
using namespace std;

 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,pos=1,snakes[3][2]={{54,19},{90,48},{99,77}},ladders[3][2]={{9,34},{40,64},{67,86}};
    while (true) {
        cin >> n;
        if (n==0) {
            cout << "You Quit!" << endl;
            return 0;
        }
        if (pos+n<=100) {
        pos+=n;
        for (int i=0;i<3;i++) {
            if (snakes[i][0]==pos) {
                pos=snakes[i][1];
            }
            else if (ladders[i][0]==pos) {
                pos=ladders[i][1];
            }
            else if (ladders[i][0] > pos && snakes[i][0] > pos) {
                break;
            }
        }
        cout << "You are now on square " << pos << endl;
        if (pos==100) {
            cout << "You Win!" << endl;
            return 0;
        }
        }
        else {
            cout << "You are now on square " << pos << endl;
        }

    }
    return 0;
 }
