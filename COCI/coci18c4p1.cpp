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

 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    char b,c,owner;int n;
    set<char>received;
    cin >> owner >> n;
    received.insert(owner);
    for (int i=0;i<n;i++) {
        cin >> b >> c;
        if (c==owner) {
            received.insert(b);
            owner=b;
        }
    }
    cout << owner << "\n" << received.size() << endl;
    return 0;
 }