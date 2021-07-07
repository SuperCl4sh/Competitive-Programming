//https://dmoj.ca/problem/ccc14s3
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
    ll a,n,t,curr;bool gone;
    cin >> t;
    deque<ll>branch,mtn;
    for (int i=0;i<t;i++) {
        curr=1;
        cin >> n;
        for (int j=0;j<n;j++) {
            cin >> a;
            branch.pf(a);
        }
        while (true) {
            gone=0;
            if (mtn.empty()&&branch.empty()) {
                cout << "Y" << endl;
                break;
        }
        if (!branch.empty()) {
            if (branch.front()==curr) {
                branch.PF();
                gone=1;
                curr++;
            }
        }
        if (!mtn.empty()) {
            if (mtn.front()==curr) {
                mtn.PF();
                gone=1;
                curr++;
            }
        }
        if (!gone) {
                if (!branch.empty()) {
                mtn.push_front(branch.front());
                branch.PF();
                }
                if (!mtn.empty()&&branch.empty()) {
                    if (mtn.front()!=curr) {
                        cout << "N" << endl;
                        break;
                    }
                    mtn.PF();
                    curr++;
                }
            }
        }
        while (!mtn.empty()) {
            mtn.pop_front();
        }
        while (!branch.empty()) {
            branch.pop_front();
        }
    }
    return 0;
 }

