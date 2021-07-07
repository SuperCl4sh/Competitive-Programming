//https://dmoj.ca/problem/ccc17j4
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
void Read(auto &num) {register int Z;num=0;bool negat=0;Z=getchar();if (Z=='-') {negat=1;Z=getchar();}for(;(Z>47&&Z<58);Z=getchar()){num=num*10+Z-48;}if(negat){num*=-1;}}
void read(auto &num) {register int Z;num=0;bool negat=0;Z=getchar_unlocked();if (Z=='-') {negat=1;Z=getchar_unlocked();}for(;(Z>47&&Z<58);Z=getchar_unlocked()){num=num*10+Z-48;}if(negat){num*=-1;}}
int main() {
	boost;
	int d;
	cin >> d;
	int ans=0;
	while (d>=720) {
		d-=720;
		ans+=31;
	}
	int hour=12,minutes=0,start,dig1,dig2,h1,h2;
	while (d>0) {
		minutes++;
		if (minutes==60) {
			if (hour==12) hour=1;
			else ++hour;
			minutes=0;
		
		}
		d--;
		if (minutes<10) continue;
		if (hour/10<1) {
		start=minutes;
		dig2=minutes%10;
		minutes/=10;
		dig1=minutes%10;
		minutes=start;
		if (hour-dig1==dig1-dig2) {
			++ans;
		}
		}
		else {
			start=minutes;
			h2=hour%10;
			h1=(hour-10)%10;
			dig2=(minutes%10);
			minutes/=10;
			dig1=minutes%=10;
			minutes=start;
			if (h1-h2==dig1-dig2&&h2-dig1==dig1-dig2) ++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}

