//https://dmoj.ca/problem/ccc08s2
#include <bits/stdc++.h>
using namespace std;
long long pennies,x,y;
void solve (long long n) {
pennies=0;
x=-n,y=n;
while (x<0) {
while (pow(x,2)+pow(y,2)>pow(n,2)) {
    pennies++;
    y--;
}
y=n;
x++;
}
return;
}
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long n,g;
    while (true) {
        cin >> n;
        if (n==0) {
            break;
        }
        solve(n);
        g=(pow(2*n+1,2)-4*pennies);
        cout << g << endl;
    }
    return 0;
 }
