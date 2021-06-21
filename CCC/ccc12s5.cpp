#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;
typedef long double ld;
typedef unsigned long long ull;
int dp[30][30];
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int k,r,c;bool broken;
    cin >> r>> c >> k;
    int cats[k][2];
    for (int i=0;i<k;i++) {
        cin >> cats[i][0] >> cats[i][1];
    }
    dp[0][0]=1;
    for (int i=0;i<r;i++) {
        for (int j=0;j<c;j++) {
            broken=0;
            for (int d=0;d<k;d++) {
                if (cats[d][0]==i+1&&cats[d][1]==j+1) {
                    broken=1;
                    break;
                }
            }
            if (broken) continue;
            if (j>0) {
                dp[i][j]+=dp[i][j-1];
            }
            if (i>0) {
                dp[i][j]+=dp[i-1][j];
            }
        }
    }
    cout << dp[r-1][c-1] << endl;
    return 0;
 }