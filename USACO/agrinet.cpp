/*
ID: 
TASK: agrinet
LANG: C++                 
*/
#include <bits/stdc++.h>
using namespace std;
ofstream fout ("agrinet.out");
ifstream fin ("agrinet.in");
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

vector<pair<int,pii>>edges;
int sizes[105],ar[105];



int par(int a) {
	while (ar[a]!=a) {
		ar[a]=ar[ar[ar[ar[a]]]];
		a=ar[a];
	}
	return a;
}

void Union(int a, int b) {
	int A=par(a),B=par(b);
	if (sizes[A]>sizes[B]) {
		sizes[B]+=sizes[A];
		ar[A]=ar[B];
	}
	else {
		sizes[A]+=sizes[B];
		ar[B]=ar[A];
	}
	return;
}

void init() {
	FOR (i,0,100) ar[i]=i,sizes[i]=1;
	return;
}


void construct() {
	sort(all(edges));
	int node1,node2,weight,ret=0;
	FOR (i,0,sz(edges)) {
		node1=edges[i].S.F,node2=edges[i].S.S,weight=edges[i].F;
		if (par(node1)!=par(node2)) {
			Union(node1,node2);
			ret+=weight;
		}
	}
	fout << ret << "\n";
	return;


}
int main() {
	boost;
	init();
	int n,a,b;
	fin >> n;
	FOR (i,0,n) {
		FOR (j,0,n) {
			fin >> a;
			if (i==j) continue;
			edges.pb({a,{i,j}});
		}
	
	}
	construct();


	return 0;
}
