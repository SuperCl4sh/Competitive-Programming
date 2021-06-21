//https://dmoj.ca/problem/occ19s2
#include <bits/stdc++.h>
using namespace std;
long long k,counter=0;
string a,b,c;
void solve (long long n) {
a = to_string(n);
b=a+"3";
c=a+"2";
long long d=stoll(b);
long long e=stoll(c);
if (d<=k) {
    counter++;
    solve(d);
}

else {
    return;
}

if (e<=k) {
    counter++;
    solve(e);
}
else {
    return;
}
return;


}
int main() {
ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
cin >> k;
solve(0);
cout << counter << endl;
return 0;
}
