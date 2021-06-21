#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define pf push_front
#define PF pop_front
#define PB pop_back
#define F first
#define S second
typedef long long ll;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;
typedef pair<double,double>pdd;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ld,ld>pld;
typedef pair<str,str>pss;

int dp[1000010];
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    str s,g;int a,lowest=INT_MAX;
    do {
        cin >> s >> a;
        if (lowest>a) {
            lowest=a;
            g=s;
        }
    }while (s.compare("Waterloo"));
    cout << g << endl;
    return 0;
 }