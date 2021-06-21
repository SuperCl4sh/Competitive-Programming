#include <bits/stdc++.h>
#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
using namespace std;
#define mp make_pair
#define pb push_back
#define pf push_front
#define PF pop_front
#define PB pop_back
#define P push
#define F first
#define S second
#define boost ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define PI 3.14159265
#define len(s) (int)s.length()
#define sz(s) (int)s.size()
#define sp(x) fixed << setprecision(x)
#define all(a) a.begin(),a.end()
typedef long long ll;
typedef string str;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;
typedef pair<double,double>pdd;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ld,ld>pld;
typedef pair<str,str>pss;
typedef pair<char,char>pcc;
typedef pair<long,long>pl;
typedef pair<bool,bool>pbb;
const ll MOD = 1000000007;
const ll high= (ll)(1e15);
const ll MOD2=998244353;
void read(auto &num) {register int Z;num=0;bool negat=0;Z=getchar();if (Z=='-') {negat=1;Z=getchar();}for(;(Z>47&&Z<58);Z=getchar()){num=num*10+Z-48;}if(negat){num*=-1;}}
str s;
int main() {
	boost;
	getline(cin,s);
	int ind=0,ans=0,curr,tot;
	while (ind<sz(s)) {
		if (s[ind]==')'||s[ind]=='('||s[ind]=='+'||s[ind]==' ') {ind++;continue;}
		if (s[ind]=='-') {
			curr=ind;
			ind++;
			while (ind<sz(s)&&isdigit(s[ind])) {
				ind++;
			}
			tot=stoi(s.substr(curr,ind-curr));
			ans+=tot;
		}
		else if (isdigit(s[ind])) {
			curr=ind;
			while (isdigit(s[ind])) {
				ind++;
			}
			tot=stoi(s.substr(curr,ind-curr));
			ans+=tot;
		}
	}
	cout << ans << "\n";
	return 0;
}