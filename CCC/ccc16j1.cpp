#include <iostream>
using namespace std;

 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tot=0;string s;
    cin >> s;
    if (s=="W") tot++;
    cin >> s;
    if (s=="W") tot++;
    cin >> s;
    if (s=="W") tot++;
    cin >> s;
    if (s=="W") tot++;
    cin >> s;
    if (s=="W") tot++;
    cin >> s;
    if (s=="W") tot++;
    if (tot==0) {
        cout << -1 << endl;
    }
    else if (5<=tot) {
        cout << 1 << endl;
    }
    else if (3<=tot) {
        cout << 2 << endl;
    }
    else {
        cout << 3 << endl;
    }
    return 0;
 }