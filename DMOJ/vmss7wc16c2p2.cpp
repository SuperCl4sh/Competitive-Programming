//https://dmoj.ca/problem/vmss7wc16c2p2
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
const int MOD=1e9+7;

 int main() {
    boost;
    str s;
    cin >> s;
    int q;cin>>q;
    int psa[s.length()];
    (s[0]=='G')?psa[0]=1:psa[0]=0;
    for (int i=1;i<s.length();i++) {
        (s[i]=='G')?psa[i]=psa[i-1]+1:psa[i]=psa[i-1];
    }
    int a,b,sum;
    while (q--) {
        cin >> a >> b;
        sum=psa[b]-psa[a];
        if (s[a]=='G') sum++;
        cout << sum << "\n";
    }
    return 0;
 }
