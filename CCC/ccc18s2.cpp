#include <bits/stdc++.h>
typedef long long ll;
int n;
using namespace std;
void solve (vector<vector<int>>ar) {
    vector<int> columns;
    vector<vector<int>>field;bool broken;
    for (int x=0;x<5;x++) {
        broken=0;
        columns.clear();
        field.clear();
        for (int i=0;i<n;i++) {
            for (int j=n-1;j>=0;j--) {
                columns.push_back(ar[j][i]);
            }
            field.push_back(columns);
            columns.clear();
        }

    for (int i=0;i<n;i++) {
        for (int j=0;j<n-1;j++) {
            if (field[i][j]<field[i][j+1]) {}
            else {
                broken=1;
                break;
            }
        }
        if (broken) {
            break;
        }
    }
    if (!broken) {
        for (int y=0;y<n;y++) {
            for (int q=0;q<n-1;q++) {
                if (field[q][y]<field[q+1][y]) {}
                else {
                    broken=1;
                    break;
                }
            }
            if (broken) {
                break;
            }
        }
    }

    if (broken) {
        for (int b=0;b<n;b++) {
            for (int a=0;a<n;a++) {
                ar[b][a]=field[b][a];
            }
        }
        continue;
    }
    for (int g=0;g<n;g++) {
        for (int w=0;w<n;w++) {
            if (w+1<n) {
            cout << field[g][w] << " ";
            }
            else {
                cout << field[g][w] << endl;
            }
        }

    }


    return;




    }
    return;

}

 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int a;
    cin >> n;
    vector<vector<int>>ar;
    vector<int> rows;
    for (int i=0;i<n;i++) {
        for (int k=0;k<n;k++) {
            cin >> a;
            rows.push_back(a);
        }
        ar.push_back(rows);
        rows.clear();
    }
    solve(ar);
    return 0;
 }