//https://dmoj.ca/problem/ccc19s1
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
    str s;int ar[2][2]={{1,2},{3,4}},totH,totV;
    cin >> s;
    for (int i=0;i<s.length();i++) {
        if (s[i]=='H') totH++;
        else totV++;
    }
    totH%=2;
    totV%=2;
    if (totV>0) {
        swap(ar[0][0],ar[0][1]);
        swap(ar[1][0],ar[1][1]);
    }
    if (totH>0) {
        swap(ar[0][0],ar[1][0]);
        swap(ar[0][1],ar[1][1]);
    }
    cout << ar[0][0] << " " << ar[0][1] << "\n" << ar[1][0] << " " << ar[1][1] << endl;


    return 0;
 }
