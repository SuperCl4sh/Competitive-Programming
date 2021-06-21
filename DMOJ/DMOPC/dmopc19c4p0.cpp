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
    str a,b;int counter=0;
    cin >>a>>b;
    for (int i=0;i<a.length();i++) {
        if (a[i]!=b[i]) {
            counter++;
        }
    }
    (counter==1)?printf("LARRY IS SAVED!\n"):printf("LARRY IS DEAD!\n");
    return 0;
 }