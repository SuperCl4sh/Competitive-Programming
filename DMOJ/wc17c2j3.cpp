//https://dmoj.ca/problem/wc17c2j3
#include <bits/stdc++.h>
using namespace std;
int counter=0,n;
void solve(int ar[],int k) {
sort(ar,ar+n);
int i=n-1;
while (i>=n/2) {
    if (ar[i]>=k) {
        counter+=2;
    }
    i--;
    //cout << i <<endl;
}
counter=min(counter,n);
return;
}
int main() {
ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int m;
cin >> n >> m;
int ar[n];
for (int i=0;i<n;i++) {
    cin >> ar[i];
}
solve (ar,m);
cout << counter << endl;
return 0;
}

