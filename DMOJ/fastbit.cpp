//https://dmoj.ca/problem/fastbit
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int tot;
int setbits(unsigned long long n) {
tot=0;
while (n) {
    n&=n-1;
    tot++;
}
return tot;
}
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    return 0;
 }

