//https://dmoj.ca/problem/dmopc17c2p2
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define pf push_front
#define PF pop_front
#define PB pop_back
#define F first
#define S second
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
 int main() {
    boost;
    str s;int ind;
    cin >> s;
    while (true) {
        ind = s.find("()");
        if (ind==-1) break;
        s.replace(s.begin()+ind,s.begin()+ind+2,"");
    }
    int counter=1;
    for (int i=0;i<s.length();i++) {
        if (s[i]=')') counter--;
        else if (s[i]=='(') counter++;
    }
    (counter==1||counter==-1)?printf("YES\n"):printf("NO\n");
    return 0;
 }

