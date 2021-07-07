//https://dmoj.ca/problem/ccc00j1
#include <string>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int total; int k=1;
    int offSet;
    int a;
    cin >>a>> total;
    if (a!=0) {
        a--;
    }
    string days = "Sun Mon Tue Wed Thr Fri Sat";
    cout << days << endl;
    for (int j=0;j<a;++j) {
        cout << "    ";
    }
    a++;
    for (int i=1;i<=total;++i) {
            if (a%8==0) {
            cout << "\n";
            a=1;
            }
        if (i<10) {
            if (a==1 || k==1) {
                cout <<"  "<< i;
                k=0;
            }
            else {
                cout <<"   "<< i;
            }
        }
        else {
            if (a==1) {
               cout << " " << i;
            }
            else {
                cout << "  " << i;
            }
        }
        a++;
    }
    cout << endl;
    return 0;
}

