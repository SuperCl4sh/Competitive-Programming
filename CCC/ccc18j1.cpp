//https://dmoj.ca/problem/ccc18j1
#include <bits/stdc++.h>
using namespace std;
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if (a==8 || a==9) {
        if (d==8 || d==9) {
            if (b==c) {
                printf("ignore");
                return 0;
            }
        }
    }
    printf("answer");
    return 0;
 }

