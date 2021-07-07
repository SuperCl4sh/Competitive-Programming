//https://dmoj.ca/problem/dwite11c2p1
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
	int n,x=0,y=0,i;bool curr,broken=0;
	for (int k=0;k<5;k++) {
		read(n);
		curr=1;i=1;x=0,y=0;
		broken=0;
		while (n>0) {
			for (int j=0;j<i;j++) {
				if (curr) {
					x++;
				}
				else y--;
				n--;
				if (n==0) {broken=1;break;}
			}
			if (broken) break;
			(curr)?curr=0:curr=1;
			i++;
		}
		printf("%i %i\n",x,y);
	}
	return 0;
}

