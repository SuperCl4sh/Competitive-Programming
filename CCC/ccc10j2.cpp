//https://dmoj.ca/problem/ccc10j2
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
int main() {
	boost;
	int a,b,c,d,s,count1=0,count2=0,counter=0,pos=0,pos1=0;bool forward=1,forward1=1;
	cin >>a >> b >> c >> d >> s;
	while (counter<s) {
		if (forward) {
			count1++,pos++;
			if (count1>=a) {count1=0,forward=0;}
		}
		else {
			count1++,pos--;
			if (count1>=b) {count1=0,forward=1;}
		}
		if (forward1) {
			count2++,pos1++;
			if (count2>=c) {
				count2=0,forward1=0;
			}
		}
		else {
			count2++,pos1--;
			if (count2>=d) {
				count2=0,forward1=1;
			}
		}
		++counter;
	}
	if (pos>pos1) {
		cout << "Nikky\n";
	}
	else if (pos<pos1) {
		cout << "Byron\n";
	}
	else {
		cout << "Tied\n";
	}
	//cout << pos << " " << pos1 << "\n";
	return 0;
}

