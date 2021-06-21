//https://dmoj.ca/problem/dpf
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
using namespace std;
#define boost ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define len(s) (int)s.length()
#define sz(s) (int)s.size()
#define sp(x) fixed << setprecision(x)
typedef long long ll;
typedef string str;
char _;
const ll MOD = 1000000007;
const ll mxN= (ll)(1e15);
void read(auto &num) {register int Z;num=0;bool negat=0;Z=getchar();if (Z=='-') {negat=1;Z=getchar();}for(;(Z>47&&Z<58);Z=getchar()){num=num*10+Z-48;}if(negat){num*=-1;}}

int main() {
    boost;
    str a,b;
    cin >> a >> b;
    int dp[len(a)+1][len(b)+1];
    memset(dp,0,sizeof(dp));
    for (int i=1;i<=len(a);i++) {
    	for (int j=1;j<=len(b);j++) {
		if (a[i-1]==b[j-1]) {
			dp[i][j]=1+dp[i-1][j-1];
		}
		else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	}
    }

    int ptr1=len(a),ptr2=len(b);
    str ans="",g;
    while (ptr1!=0&&ptr2!=0) {
    	if (a[ptr1-1]==b[ptr2-1]) {g=a[ptr1-1];ans+=g;ptr1--,ptr2--;}
	else {
		if (dp[ptr1][ptr2-1]>dp[ptr1-1][ptr2]) {
			ptr2--;
		}
		else ptr1--;
	}
    }
    reverse(ans.begin(),ans.end());
    cout << ans << "\n";
    return 0;

}

