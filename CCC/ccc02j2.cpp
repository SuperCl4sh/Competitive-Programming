//https://dmoj.ca/problem/ccc02j2
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
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
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    str s;int index;
    while (true) {
        cin >> s;
        if (s=="quit!") break;
        if (s.length()<4) {
            cout << s << endl;
            continue;
        }
        index=s.find("or");
        if (index>=s.length()) {
            cout << s << endl;
            continue;
        }
        if (index==s.length()-2&&s[index-1]!='A'&&s[index-1]!='E'&&s[index-1]!='I'&&s[index-1]!='O'&&s[index-1]!='U'&&s[index-1]!='Y'&&s[index-1]!='a'&&s[index-1]!='e'&&s[index-1]!='i'&&s[index-1]!='o'&&s[index-1]!='u'&&s[index-1]!='y') {
            cout << s.replace(index,index+2,"our")<< endl;
            continue;
        }
        else {
            cout << s << endl;
        }
    }
    return 0;
 }

