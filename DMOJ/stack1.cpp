//https://dmoj.ca/problem/stack1
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;
typedef long double ld;
typedef unsigned long long ull;

 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,m;str a,b;
    cin >> t >> m;
    deque<str>drive;

    for (int i=0;i<t;i++) {
        cin >> a >> b;
        if (b=="in") {
            drive.push_back(a);
        }
        else {
            if (!a.compare(drive.front())&&m&&!drive.empty()) {
                drive.pop_front();
                m--;
            }
            else if (!a.compare(drive.back())&&m&&!drive.empty()) {
                drive.pop_back();
                m--;
            }
        }
    }
    while (!drive.empty()) {
        cout << drive.front() << endl;
        drive.pop_front();
    }
    return 0;
 }
