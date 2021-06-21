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
    int r,c;double tot=0,counter=0;
    cin >> r >> c;
    double ar[r][c];
    for (int i=0;i<r;i++) {
        for (int j=0;j<c;j++) {
            cin >> ar[i][j];
            tot+=ar[i][j];
            counter++;
        }
    }
    tot/=counter;
    if (abs(tot-0.48)<=1e-5) {
        cout << "correctly exposed" << endl;
        return 0;
    }
    else if (tot>0.48) {
        cout << "overexposed" << endl;
    }
    else {
        cout << "underexposed" << endl;
    }
    double left=0,right=480,m,total=0;
    while (right-left>0.0000001) {
        total=0.0;
        m=(left+right)/2.0;
        for (int i=0;i<r;i++) {
            for (int j=0;j<c;j++) {
                if (ar[i][j]*m>1) total++;
                else {
                total+=m*ar[i][j];
                }
            }
        }
        total/=counter;
        if (total>0.48) {
            right=m;
        }
        else left=m;
    }
    cout << m << endl;
    return 0;
 }