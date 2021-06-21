//https://dmoj.ca/problem/encode
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
    ll n;str s,alpha="abcdefghijklmnopqrstuvwxyz",upperAlpha="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    getline(cin,s);
    n=stoi(s);
    getline(cin,s);
    int ind=0;str ans="",g;
    for (int i=0;i<s.length();i++) {
        if (s[i]==' ') {
            cout << " ";
        }
        else if (isupper(s[i])) {
            for (int j=0;j<upperAlpha.length();j++) {
                if (s[i]==upperAlpha[j]) {
                    ind=j;
                    break;
                }
            }
            ind-=n;
            if (ind>0) ind%=26;
            while (ind<0) ind+=26;

            cout << upperAlpha[ind];

        }
        else {
            for (int j=0;j<alpha.length();j++) {
                if (s[i]==alpha[j]) {
                    ind=j;
                    break;
                }
            }
            ind-=n;
            if (ind>0) ind%=26;
            while (ind<0) ind+=26;
            cout << alpha[ind];
        }
    }
    cout << endl;

    return 0;
 }
