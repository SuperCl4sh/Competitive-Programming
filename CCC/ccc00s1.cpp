//https://dmoj.ca/problem/ccc00s1
#include <bits/stdc++.h>
using namespace std;
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int d,a,b,c,ans=0;
    cin >> d >> a >> b >> c;
    while (d>0) {
        d--;
        a++;
        ans++;
        if (a==35) {
            d+=30;
            a=0;
        }
        if (d>0) {
            b++;
            d--;
            ans++;
        }
        if (b==100) {
            b=0;
            d+=60;
        }
        if (d>0) {
            c++;
            d--;
            ans++;
        }
        if (c==10) {
            c=0;
            d+=9;
        }
    }
    cout << "Martha plays " <<ans<<" times before going broke."<<endl;
    return 0;
 }

