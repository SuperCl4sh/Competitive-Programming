//https://dmoj.ca/problem/dmpg16b2
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define pf push_front
#define PF pop_front
#define PB pop_back
#define P push
#define F first
#define S second
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define make_tuple MT
#define PI 3.14159265
typedef long long ll;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;
typedef pair<double,double>pdd;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ld,ld>pld;
typedef pair<str,str>pss;
char _;
 int main() {
    boost;
    int t,n;double a,b,tot=0;
    cin >> t;
    while (t--) {
        cin >> n >> a;
        tot=0;
        for (int i=1;i<n;i++) {
            cin >> b;
            if (a<b) tot++;
        }
        cout << fixed << setprecision(2) << "Bob wins $" << 100.0*sqrt(n-tot) << " at IOI!\n";
    }
    return 0;
 }

