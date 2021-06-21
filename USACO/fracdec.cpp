/*
ID: 
TASK: fracdec
LANG: C++                 
*/
#include <bits/stdc++.h>
using namespace std;
ofstream fout ("fracdec.out");
ifstream fin ("fracdec.in");
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
#define FOR(i,a,n) for (int i=a;i<n;i++)
typedef long long ll;
typedef string str;
typedef vector<ll>vll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;
typedef pair<long double, long double>pld;
typedef pair<double,double>pdd;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ld,ld>pld;
typedef pair<str,str>pss;
typedef pair<char,char>pcc;
typedef pair<long,long>pl;
typedef pair<bool,bool>pbb;
const ll MOD = 1000000007LL;
const ll MOD2=998244353LL;
const ll high= (ll)(1e15);
void read(auto &num) {register int Z;num=0;bool negat=0;Z=getchar();if (Z=='-') {negat=1;Z=getchar();}for(;(Z>47&&Z<58);Z=getchar()){num=num*10+Z-48;}if(negat){num*=-1;}}
void Read(auto &num) {register int Z;num=0;bool negat=0;Z=getchar_unlocked();if (Z=='-') {negat=1;Z=getchar_unlocked();}for(;(Z>47&&Z<58);Z=getchar_unlocked()){num=num*10+Z-48;}if(negat){num*=-1;}}
ll modmul(ll a, ll b, ll m) {ll ans=a*b-m*ll(1.L/m*a*b);return ans+m*(ans<0)-m*(ans>=m);}
ll Pow(ll a, ll b, ll mod) {ll ans=1;for (; b;a=modmul(a,a,mod),b/=2) {if (b&1) ans=modmul(ans,a,mod);}return ans;}

int indices[1000005],counter=0;

int calc(int n) {
	if (n==0) return 1;
	int ret=0;
	while (n) ++ret,n/=10;
	return ret;
}

void Print(str s) {
	FOR (i,0,sz(s)) {
		fout << s[i];
		if (counter==75) {counter=-1;fout<<"\n";}
		++counter;
	}
	if (counter) fout << "\n";
	return;
}


int main() {
	boost;
	int n,d;
	fin >> n >> d;
	fout << n/d << ".";	
	if (!(n%d)) {
		fout << "0\n";
		return 0;
	}
	int New,next,remainder;
	counter=calc(n/d)+1;
	str finalAns="";
	n%=d;
	map<int,bool>visited;
	int ind=0;
	while (1) {
		New=(10*n)/d;
		remainder=(10*n)%d;
		if (visited[10*n]) break;	
		finalAns+=to_string(New);
		if (remainder==0) break;
		visited[10*n]=1,indices[10*n]=ind;
		n=remainder;
		++ind;
	}
	//cout << finalAns << "\n";
	if (remainder==0) {
		Print(finalAns);
	}
	else {
		finalAns.insert(indices[10*n],"(");
		finalAns+=")";
		Print(finalAns);
	
	}

	
	
	return 0;
}
