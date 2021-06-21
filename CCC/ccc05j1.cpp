#include <bits/stdc++.h>
using namespace std;

 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    float a,b,c;
    cin >> a >> b >> c;
    float planA=(a-100)*0.25;
    planA=max(0.0F,planA);
    planA+=0.15*b+0.20*c;
    float planB = (a-250)*0.45;
    planB=max(planB,0.0F);
    planB+=0.35*b+0.25*c;

    cout << fixed << setprecision(2) << "Plan A costs " << planA << endl;
    cout << fixed << setprecision(2) << "Plan B costs " << planB << endl;
    if (planA>planB) {
        cout << "Plan B is cheapest." << endl;
    }
    else if (planB>planA) {
        cout << "Plan A is cheapest." << endl;
    }
    else {
        cout << "Plan A and B are the same price." << endl;
    }
    return 0;
 }