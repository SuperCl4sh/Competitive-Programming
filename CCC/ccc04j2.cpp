#include <bits/stdc++.h>
using namespace std;
int main() {
ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int x,y;
cin >> x >>y;
while (x<=y) {
    printf("All positions change in year %i\n",x);
    x+=60;
}
return 0;
}