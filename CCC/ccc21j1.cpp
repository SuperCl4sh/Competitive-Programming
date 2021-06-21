//https://dmoj.ca/problem/ccc21j1
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int b;
    cin >> b;
    cout << 5*b-400 << "\n";
    int ans=5*b-400;
    if (ans==100) cout << 0 << "\n";
    else if (ans<100) cout << 1 << "\n";
    else cout << -1 << "\n";
    
    
    return 0;
}
