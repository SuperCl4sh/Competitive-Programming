//https://dmoj.ca/problem/p175ex5
#include <bits/stdc++.h>
using namespace std;
int n;
string ans="";
void solve(vector<vector<int>>nums) {
    ans="";
    int total=0,requiredTotal=0;
    int ar[n]={0};
    int k=0;
    for (int i=0;i<n;i++) {
        requiredTotal+=nums[k][i];
    }
for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
        total+=nums[i][j];
        ar[j]+=nums[i][j];
    }
    if (requiredTotal!=total) {
        ans="no";
        return;
    }
    else {
        total=0;
    }
}
for (int i=1;i<n;i++) {
    if (ar[i]!=ar[i-1]) {
        ans="no";
        return;
    }
}
ans="yes";
return;
}

int main() {
ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int t,r,c,a,d;
cin >> t;
while (t--) {
    r,c=0,0;
    cin >> n;
    vector<vector<int>>nums;
    vector<int>rows;
    d=pow(n,2);
    while (d--) {
        cin >> a;
        rows.push_back(a);
        c++;
        if (c==n) {
            c=0;
            r++;
            nums.push_back(rows);
            rows.clear();
        }
    }
    solve(nums);
    cout << ans << endl;
    nums.clear();
}
return 0;
}
