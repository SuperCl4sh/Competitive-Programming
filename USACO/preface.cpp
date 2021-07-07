/*
ID:  
TASK: preface
LANG: C++                 
*/
#include <bits/stdc++.h>
#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
using namespace std;
ofstream fout ("preface.out");
ifstream fin ("preface.in");
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
#define mem(ar,a) memset(ar,a,sizeof(ar))
#define MT make_tuple
typedef long long ll;
typedef string str;
typedef vector<ll>vll;
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
const ll MOD=998244353LL;
const ll high= (ll)(1e15);
const ll MOD2 = 1000000007LL;
void read(auto &num) {register int Z;num=0;bool negat=0;Z=getchar();if (Z=='-') {negat=1;Z=getchar();}for(;(Z>47&&Z<58);Z=getchar()){num=num*10+Z-48;}if(negat){num*=-1;}}
void Read(auto &num) {register int Z;num=0;bool negat=0;Z=getchar_unlocked();if (Z=='-') {negat=1;Z=getchar_unlocked();}for(;(Z>47&&Z<58);Z=getchar_unlocked()){num=num*10+Z-48;}if(negat){num*=-1;}}
ll modmul(ll a, ll b, ll m) {ll ans=a*b-m*ll(1.L/m*a*b);return ans+m*(ans<0)-m*(ans>=m);}
ll Pow(ll a, ll b, ll mod) {ll ans=1;for (; b;a=modmul(a,a,mod),b/=2) {if (b&1) ans=modmul(ans,a,mod);}return ans;}
void Print(auto &temp) {for (auto x: temp) cout << x << " ";cout << "\n";return;}
str convert(int n) {
	str ret="";
	int vals[]={1,4,5,9,10,40,50,90,100,400,500,900,1000};
	str convertChars[]={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
	for (int i=12;i>=0&&n>0;i--) {
		int counter=n/vals[i];
		n%=vals[i];
		for (int j=0;j<counter;j++) ret+=convertChars[i];
	}
	return ret;
}
int main() {
	boost;
	int n;
	fin >> n;
	int ar[100];
	mem(ar,0);
	str alpha="IVXLCDM";
	for (int i=1;i<=n;i++) {
		str curr=convert(i);
		for (int j=0;j<sz(curr);j++) {
			if (curr[j]=='I') ar[0]++;
			else if (curr[j]=='V') ar[1]++;
			else if (curr[j]=='X') ar[2]++;
			else if (curr[j]=='L') ar[3]++;
			else if (curr[j]=='C') ar[4]++;
			else if (curr[j]=='D') ar[5]++;
			else ar[6]++;
		}
	}
	for (int i=0;i<7;i++) {
		if (ar[i]>0) fout << alpha[i] << " " << ar[i] << "\n";
	}
	
	
	return 0;
}

