//https://dmoj.ca/problem/utso18p3
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
    int a,n,t,k,v,tot=0,ans=0,curr=1;
    cin >> n >> t >> k >> v;
    int ar[n+1];
    if (k>t) {printf("0");return 0;}
    memset(ar,0,sizeof(ar));
    for (int i=0;i<v;i++) {
        cin >> a;
        ar[a]=1;
    }
    for (int i=1;i<=t;i++) {
        if (ar[i]) tot++;
    }
    for (int i=1;i+t-1<=n;i++) {
        if (i>1) {
        tot-=ar[i-1];tot+=ar[i+t-1];
        }
        if (tot>=k) continue;
        for (int j=t+i-1;j>=i&&j<=n;j--) {
            if (ar[j]==0) {ans++,tot++;ar[j]=1;}
            if (tot>=k) break;
        }
    }
    printf("%i\n",ans);
    return 0;
 }

