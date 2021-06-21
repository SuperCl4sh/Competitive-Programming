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
const int MOD=(int)(1e9)+7;
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
    str s;
    cin >> s;
    int tot=0,sign,sign2;str g;
    for (int i=1;i<s.length();i+=2) {
        g=s[i-1];
        if (s[i]=='I') sign=1;
    else if (s[i]=='V') sign=5;
    else if (s[i]=='X') sign=10;
    else if (s[i]=='L') sign=50;
    else if (s[i]=='C') sign=100;
    else if (s[i]=='D') sign=500;
    else if (s[i]=='M') sign=1000;
    if (i+2<s.length()) {
    if (s[i+2]=='I') sign2=1;
    else if (s[i+2]=='V') sign2=5;
    else if (s[i+2]=='X') sign2=10;
    else if (s[i+2]=='L') sign2=50;
    else if (s[i+2]=='C') sign2=100;
    else if (s[i+2]=='D') sign2=500;
    else if (s[i+2]=='M') sign2=1000;
    }
    else sign2=INT_MIN;
                if (sign<sign2) {
                    tot-=stoi(g)*sign;
                }
                else tot+=stoi(g)*sign;
    }
    cout << tot << "\n";

    return 0;
 }