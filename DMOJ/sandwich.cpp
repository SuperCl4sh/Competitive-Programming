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
    int n;str s;
    cin >> n >> s;
    deque<int>q;
    for (int i=1;i<=n;i++) {
        if (s[i-1]=='0') {
            q.push_back(i);
        }
        else {
            q.push_front(i);
        }
    }
    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop_front();
    }
    return 0;
 }