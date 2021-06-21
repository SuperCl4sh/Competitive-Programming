#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;int tot1=0;int tot2=0;int day=0;
    cin >> n;
    vector <int> team1(n);
    vector <int> team2(n);
    for (int i=0;i<n;i++) {
            cin >> team1[i];
    }
    for (int i=0;i<n;i++) {
        cin >> team2[i];
        tot1+=team1[i];
        tot2+=team2[i];
        if (tot1==tot2) {
            day=i+1;
        }
    }
    cout << day << endl;
    return 0;

}