/*
ID: 
TASK: dualpal
LANG: C++                 
*/

#include <bits/stdc++.h>

#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
using namespace std;
ofstream fout ("dualpal.out");
ifstream fin ("dualpal.in");
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
const ll MOD2 = (int)((int)(1e9)+7);
void read(auto &num) {register int Z;num=0;bool negat=0;Z=getchar();if (Z=='-') {negat=1;Z=getchar();}for(;(Z>47&&Z<58);Z=getchar()){num=num*10+Z-48;}if(negat){num*=-1;}}
void Read(auto &num) {register int Z;num=0;bool negat=0;Z=getchar_unlocked();if (Z=='-') {negat=1;Z=getchar_unlocked();}for(;(Z>47&&Z<58);Z=getchar_unlocked()){num=num*10+Z-48;}if(negat){num*=-1;}}
str alphabet="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
bool palin(str s) {
	for (int i=0,j=sz(s)-1;j>i;j--,i++) {
		if (s[i]!=s[j]) return 0;
	}
	return 1;
}
int Log (int base, int start) {
	int ans=0,curr=1;
	while (true) {
		if (curr>start) break;
		++ans;curr*=base;
	}
	return ans-1;
}
str convert(int start, int base) {
	str ans="";int ar[10000],Start=0;
	memset(ar,0,sizeof(ar));
	while (start>0) {
		int b=Log(base,start);
		Start=max(Start,b);
		int c= pow(base,b);
		ar[b]+=int(start/c);
		start-=int(start/c)*c;
	}
	for (int i=Start;i>=0;i--) {
		if (ar[i]<10) {
			ans+=to_string(ar[i]);
		}
		else ans+=alphabet[ar[i]-10];
	}

	return ans;
}
void solve(int n,int e) {
	
	int i=e+1,counter=0;
	while (true) {
		bool good=0;
		for (int j=2;j<=10;j++) {
			str curr=convert(i,j);
			if (palin(curr)) {
				if (good) {
					fout << i << "\n";
					++counter;
					break;
			}
			good=1;
			}
		}
		if (counter==n) break;
		++i;
	}
	return;
}
int main() {
    boost;
    int n,e;
    fin >> n >> e;
    solve(n,e);
    
    return 0;
}
