#include <bits/stdc++.h>
using namespace std;

 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,d,c,tot1,tot2;
    cin >> n >> d;
    vector<int>ar(n);
    vector <int>t1;
    vector<int>t2;
    for (int i=0;i<n;i++) cin >> ar[i];
    while (d--) {
        t1.clear();
        t2.clear();
        cin >> c;
        tot1=0,tot2=0;
        for (int i=0;i<ar.size();i++) {
            if (i>=c) {
                t2.push_back(ar[i]);
                tot2+=t2[t2.size()-1];
            }
            else {
                t1.push_back(ar[i]);
                tot1+=t1[t1.size()-1];
            }
            //cout << tot1 << " " << tot2 << endl;
        }

        ar.clear();
        if (tot1>=tot2) {
            for (int i=0;i<t2.size();i++) {
                ar.push_back(t2[i]);
            }
            cout << tot1 << endl;
        }
        else {
            cout << tot2 << endl;
            for (int i=0;i<t1.size();i++) {
            ar.push_back(t1[i]);

            }
        }
    }
    return 0;
 }