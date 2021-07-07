/*
ID: 
TASK: namenum
LANG: C++                 
*/
#include <bits/stdc++.h>
#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
using namespace std;
ifstream Cin ("dict.txt");
ofstream fout ("namenum.out");
ifstream fin ("namenum.in");
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
void Read(auto &num) {register int Z;num=0;bool negat=0;Z=getchar_unlocked();if (Z=='-') {negat=1;Z=getchar_unlocked();}for(;(Z>47&&Z<58);Z=getchar_unlocked()){num=num*10+Z-48;}if(negat){num*=-1;}}
int main() {
	boost;
	str a,s,alphabet="ABCDEFGHIJKLMNOPRSTUVWXY";
	fin >> s;
	vector<str>ans,possible;
	while (true) {
		Cin >> a;
		if (sz(a)==sz(s)) possible.pb(a);
		if (Cin.eof()) break;
	}
	vector<vector<char>>ar;
	for (int i=0;i<24;i+=3) {
		vector<char>row;
		for (int j=i;j<i+3;j++) {
			row.pb(alphabet[j]);
		}
		ar.pb(row);
	}
	char A,B,C;
	for (int i=0;i<sz(s);i++) {
		int n=s[i]-'0';
		vector<str>Possible;
		n-=2;
		A=ar[n][0],B=ar[n][1],C=ar[n][2];
		for (int j=0;j<sz(possible);j++) {
			if (possible[j][i]==A||possible[j][i]==B||possible[j][i]==C) Possible.pb(possible[j]);
		}
		possible=Possible;
	}
	if (possible.empty()) fout << "NONE\n";
	else {
		for (int i=0;i<sz(possible);i++) {
			fout << possible[i] << "\n";
		}
	}
	
	return 0;
}

