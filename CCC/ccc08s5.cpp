//https://dmoj.ca/problem/ccc08s5
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
using namespace std;
#define mp make_pair
#define pb push_back
#define pf push_front
#define PF pop_front
#define PB pop_back
#define P push
#define F first
#define S second
#define scann(speed){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}speed=s*f;}
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define make_tuple MT
#define PI 3.14159265
#define len(s) (int)s.length()
#define sz(s) (int)s.size()
#define sp(x) fixed << setprecision(x)
typedef long long ll;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;
typedef pair<double,double>pdd;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ld,ld>pld;
typedef pair<str,str>pss;
typedef pair<char,char>pcc;
typedef pair<long,long>pl;
char _;
const ll MOD = 1000000007;
const ll mxN= (ll)(1e15);
void read(auto &num) {register int Z;num=0;bool negat=0;Z=getchar();if (Z=='-') {negat=1;Z=getchar();}for(;(Z>47&&Z<58);Z=getchar()){num=num*10+Z-48;}if(negat){num*=-1;}}
int main() {
	boost;
	bool dp[31][31][31][31];
	memset(dp,0,sizeof(dp));
	for (int a=0;a<31;a++) {
		for (int b=0;b<31;b++) {
			for (int c=0;c<31;c++) {
				for (int d=0;d<31;d++) {
					if (a>=2&&b>=1&&d>=2) {
						if (!dp[a-2][b-1][c][d-2]) {dp[a][b][c][d]=1;continue;}
					}
					if (a>=1&&b>=1&&c>=1&&d>=1) {
						if (!dp[a-1][b-1][c-1][d-1]) {dp[a][b][c][d]=1;continue;}
					}
					if (c>=2&&d>=1) {
						if (!dp[a][b][c-2][d-1]) {dp[a][b][c][d]=1;continue;}
					}
					if (b>=3) {
						if (!dp[a][b-3][c][d]) {dp[a][b][c][d]=1;continue;}
					}
					if (a>=1&&d>=1) {
						if (!dp[a-1][b][c][d-1]) {dp[a][b][c][d]=1;continue;}
					}
				}
			}
		}
	}
	int n;
	read(n);
	int w,x,y,z;
	for (int i=0;i<n;i++) {
		read(w);read(x);read(y);read(z);
		if (!dp[w][x][y][z]) printf("Roland\n");
		else printf("Patrick\n");
	}
	return 0;
}
