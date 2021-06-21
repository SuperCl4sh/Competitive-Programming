//https://dmoj.ca/problem/tsoc15c2p2
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

 int main() {
    boost;
    int n;
    cin >> n;
    int left=(n+1)/2-1,right=(n+1)/2-1;
    bool first=1;
    if (n==3) cout << "***";
    while (left>=2) {
        if (first) {
            for (int i=0;i<n;i++) {
                cout << "*";
            }
            cout << "\n";
            first=0;
            continue;
        }
        else {
        for (int i=0;i<n;i++) {
            if (i>=left&&i<=right) {
                cout << " ";
            }
            else {
                cout << "*";
            }
        }
        }
        if (left-1>1) {
        cout << "\n";
        }
        left--,right++;
    }
        left--,right++;
    while (left<=right) {
        for (int i=0;i<n;i++) {
            if (i>=left&&i<=right) cout << " ";
            else cout << "*";
        }
        cout<<"\n";
        left++,right--;
    }
    for (int i=0;i<n;i++) {
        cout << "*";
    }
    cout << "\n";
    return 0;
 }
