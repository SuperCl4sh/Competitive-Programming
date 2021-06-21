//https://dmoj.ca/problem/wc17c3j1
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

 int main() {
    boost;
    double g;
    double n;int ans=0;cin>>n;
    ans++,n++;
    while (n!=10&&n!=100&&n!=1000){
        g=log10(n);
        ans++,n++;
    }
    cout << ans << "\n";
    return 0;
 }
