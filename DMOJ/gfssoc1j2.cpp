//https://dmoj.ca/problem/gfssoc1j2
#include <bits/stdc++.h>
using namespace std;
int main() {
ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int m,n,x=0,y=0;string s;
cin >> n;
for (int i=0;i<n;i++) {
    cin >> s>> m;
    if (s=="North")y+=m;
    else if(s=="South") y-=m;
    else if(s=="East") x+=m;
    else x-=m;
}
cout << x <<" "<<y<<endl;
return 0;
}

