//https://dmoj.ca/problem/mockccc14s1
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
    str a,b,curr,g;
    getline(cin,a);
    getline(cin,b);
    reverse(b.begin(),b.end());
    int ind=-1;
    for (int i=0;i<a.length();i++) {
        curr=a.substr(i,b.length());
        if (!curr.compare(b)) ind=i;
    }
    if (ind==-1) cout << -1 << endl;
    else cout << ind+b.length() << endl;
    return 0;
 }

