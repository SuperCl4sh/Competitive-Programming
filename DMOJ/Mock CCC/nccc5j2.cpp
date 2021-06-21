//https://dmoj.ca/problem/nccc5j2
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
int freq[15];
 int main() {
    boost;
    int n;
    cin >> n;
    int ar[n];
    for (int i=0;i<n;i++) {
        cin >> ar[i];
    }

    memset(freq,0,sizeof(freq));
    for (int i=0;i<n;i++) {
        freq[ar[i]]++;
    }
    int num=0;
    for (int i=0;i<15;i++) {
        if (freq[i]>freq[num]) num=i;
    }
    cout << num << "\n";
    return 0;
 }
