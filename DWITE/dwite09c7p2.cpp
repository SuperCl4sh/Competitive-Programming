#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;
typedef long double ld;
typedef unsigned long long ull;
bool sieve[100005];
vector<ull>primes;
void Sieve() {
int j;
for (ull i=2;i<=100000;i++) {
    if (!sieve[i]) {
        primes.push_back(i);
        j=2*i;
        while (j<=100000) {
            sieve[j]=1;
            j+=i;
        }
    }
}
return;
}
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    Sieve();
    ull n,tot=1,index;
    for (int i=0;i<5;i++) {
        cin >> n;
        tot=0;
        index=0;
        while (true) {
            if (primes[index]<=n) {
                tot+=primes[index];
                index++;
            }
            else {
                break;
            }
        }
        cout << tot << endl;
    }
    return 0;
 }