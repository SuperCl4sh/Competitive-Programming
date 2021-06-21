#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main() {

    int numerator;int denominator;
    cin >> numerator >> denominator;
    int num=numerator/denominator;
    numerator=numerator%denominator;
    for (int i=2;i<=numerator;i++) {
        while (numerator%i==0 && denominator%i==0) {
            numerator/=i;
            denominator/=i;
        }
    }
    if (numerator==0) {
        cout << num;
    }
    else if (num==0) {
        cout << numerator << "/" << denominator;
    }
    else {
    cout << num << " " << numerator << "/" << denominator;
    }
    cout << endl;
    return 0;
}