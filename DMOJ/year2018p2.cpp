//https://dmoj.ca/problem/year2018p2
#include <bits/stdc++.h>
using namespace std;
bool sieve[100500];
void primes () {
int j;
sieve[1]=1,sieve[0]=1;
for (int i=2;i<=317;i++) {
    if (!sieve[i]) {
        j=2*i;
        while (j<=100100) {
            sieve[j]=1;
            j+=i;
        }
    }
}
return;
}
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    primes();
    int n,g,tot=0;
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >>g;
        if (!sieve[g])tot++;
    }
    cout << tot << endl;
    return 0;
 }

