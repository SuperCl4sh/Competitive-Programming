//https://dmoj.ca/problem/crci06p1
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
	int n,e,a,b;
	read(n);read(e);
	vector<vector<int>>ar;
	vector<int>row;
	for (int i=0;i<e;i++) {
		read(a);
		for (int j=0;j<a;j++) {
			read(b);
			row.pb(b);
		}
		sort(row.begin(),row.end());
		ar.pb(row);
		row.clear();
	}
	int curr=0;bool broken;
	bool heard[101][101];
	memset(heard,0,sizeof(heard));
	for (int i=0;i<e;i++) {
		if (ar[i][0]==1) {
			++curr;
		for (auto j:ar[i]) {
			heard[j][curr]=1;
		}
		}
		else {
		for (int j=0;j<sz(ar[i]);j++) {
			for (int k=0;k<sz(ar[i]);k++) {
				for (int w=1;w<=curr;w++) {
					if (heard[ar[i][j]][w]) {
						heard[ar[i][k]][w]=1;
					}
					if (heard[ar[i][k]][w]) {
						heard[ar[i][j]][w]=1;
					}
				}
			}
		}
		}

	}
	for (int c=1;c<=n;c++) {
		for (int x=1;x<=curr;x++) {
			if (!heard[c][x]) break;
			if (x==curr) printf("%i\n",c);
		}
	}
	

	
	
	
	return 0;
}
