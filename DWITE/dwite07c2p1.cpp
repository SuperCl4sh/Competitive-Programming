#include <bits/stdc++.h>
using namespace std;
string s="not";
int sieve[101];
vector <int> primes;
vector <int> semiprimes;
void sieveSolve () {
    int j;
    for (int i=2;i<100;i++){
            j=i;
        if (sieve[i]==0) {
           primes.push_back(j);
            while (j+i<100) {
                sieve[j+i]=1;
                j+=i;
            }
        }
    }
    for (int i=0;i<primes.size();i++) {
        for (int j=i;j<primes.size();++j) {
            semiprimes.push_back(primes[i]*primes[j]);
        }
    }
    return;
}
void solve (int b) {
    s="not";
    for (int i=0;i<semiprimes.size();i++) {
        if (semiprimes[i]==b) {
            s="semiprime";
            return;
        }
    }
    return;




}
int main() {
ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
sieveSolve();
int a;
for (int i=0;i<5;i++) {
    cin >> a;
solve(a);
cout << s << endl;
}
return 0;
}