//https://dmoj.ca/problem/dmopc14c5p2
#include <bits/stdc++.h>

using namespace std;

int main() {
int n;
int a,b,highest=1;
cin >> n;
for (int i=0;i<n;i++) {
    cin >> a >> b;
    highest=max(highest,b-a);
}
cout << highest << endl;

}
