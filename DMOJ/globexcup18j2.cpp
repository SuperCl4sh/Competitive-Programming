//https://dmoj.ca/problem/globexcup18j2
#include <bits/stdc++.h>
using namespace std;
int main() {
ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
double n;double average=0.0;
cin >> n;
vector <double> nums(n);
for (int i=0;i<n;i++) {
    cin >> nums[i];
    average+=nums[i];
}
average/=n;
double counter=0;
for (int i=0;i<n;i++) {
    if (nums[i]>average) {
        counter++;
    }
}
double percent=100*(counter/n);
if (percent > 50) {
    cout << "Winnie should take the risk" << endl;
}
else {
    cout << "That's too risky" << endl;
}
return 0;
}

