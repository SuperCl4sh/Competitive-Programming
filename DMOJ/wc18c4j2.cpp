//https://dmoj.ca/problem/wc18c4j2
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
#define MOD 1e9+7
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
    int a,n,tot=0,curr=50;
    cin >> n;
    while (n--) {
        cin >> a;
        if (a>0) curr=min(curr+a,50);
        else curr+=a;
        if (curr<=0) tot++,curr=10;
    }
    cout << tot << "\n";
    return 0;
 }

