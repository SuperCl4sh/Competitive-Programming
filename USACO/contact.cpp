/*
ID: 
TASK: contact
LANG: C++                 
*/
#include <bits/stdc++.h>
using namespace std;
ofstream fout ("contact.out");
ifstream fin ("contact.in");
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
#define vt vector
typedef long long ll;
typedef string str;
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

vt<vt<str>>possib(15);

unordered_map<int,int>calc;

bool compareBySize(const pii &a, const pii &b) {
	if (a.S!=b.S) return a.S<b.S;
	return a.F<b.F;
}

void compute(str s, int k) {
	if (k>sz(s)) return;
	int needle=stoi(s.substr(0,k),0,2);
	calc[needle]++;
	FOR (i,1,sz(s)-k+1) {
		needle-=(s[i-1]-'0')*(1<<(k-1));
		needle*=2;
		needle+=(s[i+k-1]-'0');
		calc[needle]++;
	}
	return;

}

str convert(int n,int a) {
	str ret="";
	FOR (i,0,a) ret+="0";
	int ind=a-1;
	while (n) {
		if (n&1) ret[ind]='1';
	        n>>=1;	
		--ind;
	}
	return ret;



}

int main() {
	boost;

	int a,b,n;str s="",S;
	fin >> a >> b >> n;
	
	while (1) {
		fin >> S;
		if (fin.eof()) break;
		s+=S;
	}
	vt<vt<pii>>ans(200001);
	map<str,bool>visited;
	int Counter=0;
	FOR (i,a,b+1) {
		calc.clear();
		compute(s,i);
		for (auto it=calc.begin();it!=calc.end();++it) {
			ans[it->S].pb(mp(it->F,i));
			//cout << it->F << " " << it->S << "\n";
		}
	}
	
	int counter=0;
	for (int i=200000;i>0&&counter<n;i--) {
		if (ans[i].empty()) continue;
		fout << i << "\n";
		sort(all(ans[i]),compareBySize);
		int Counter=0;


		FOR (j,0,sz(ans[i])) {
			fout << convert(ans[i][j].F,ans[i][j].S);
			if (j+1<sz(ans[i])&&Counter<5) {fout << " ";}
			else {Counter=-1;fout << "\n";}
			++Counter;
		}
		++counter;
	}
	
	

	return 0;
}
