//https://dmoj.ca/problem/ccc09s1
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
    int a,b,tot=0,curr=1;
    cin >> a >> b;
    while (pow(curr,6)<=b) {
        if (a<=pow(curr,6)&&pow(curr,6)<=b) tot++;
        curr++;
    }
    cout << tot << endl;

    return 0;
 }
