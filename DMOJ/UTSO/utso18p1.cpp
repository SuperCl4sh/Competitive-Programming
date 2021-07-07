//https://dmoj.ca/problem/utso18p1
#include <bits/stdc++.h>
using namespace std;
int main() {
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
long long a,b,c,d,e;
cin >> a >> b;
d=a+b;
c=max(a-b,b-a);
e=a*b;
cout << max(max(d,c),e) << endl;
return 0;
}

