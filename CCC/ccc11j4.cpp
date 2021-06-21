//https://dmoj.ca/problem/ccc11j4
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
void Read(auto &num) {register int Z;num=0;bool negat=0;Z=getchar_unlocked();if (Z=='-') {negat=1;Z=getchar_unlocked();}for(;(Z>47&&Z<58);Z=getchar_unlocked()){num=num*10+Z-48;}if(negat){num*=-1;}}
bool visited[401][401];
void initialize() {
	int x=5,y=3;
	for (int i=0;i<2;i++) {
		visited[x][y]=1;
		++x;
	}
	for (int i=0;i<8;i++) {
		visited[x][y]=1;
		++y;
	}
	for (int i=0;i<4;i++) {
		visited[x][y]=1;
		--x;
	}
	for (int i=0;i<2;i++) {
		visited[x][y]=1;
		y--;
	}
	for (int i=0;i<2;i++) {
		visited[x][y]=1;
		++x;
	}
	for (int i=0;i<2;i++) {
		visited[x][y]=1;
		--y;
	}
	for (int i=0;i<2;i++) {
		visited[x][y]=1;
		--x;
	}
	for (int i=0;i<3;i++) {
		visited[x][y]=1;
		--y;
	}
	for (int i=0;i<3;i++) {
		visited[x][y]=1;
		--x;
	}

	return;
}
int main() {
	boost;
	char a;int b,x=5,y=3;
	initialize();
	bool impossible=0;
	while (true) {
		cin >> a >> b;
		if (a=='q') break;
		int sx=x,sy=y;
		for (int i=0;i<b;i++) {
			if (a=='l') y--;
			else if (a=='r') y++;
			else if (a=='d') ++x;
			else if (a=='u') --x;
			if (visited[x][y]) {
				if (a=='l') cout << sy-b-4 << " " << -1*sx;
				else if (a=='r') cout << sy+b-4 << " " << -1*sx;
				else if (a=='d') cout << sy-4 << " " << -1*sx-b;
				else cout << sy-4 << " " << -1*sx+b;
				cout << " DANGER\n";
				impossible=1;
				break;
			}
			visited[x][y]=1;
		}
		if (impossible) break;
		cout << y-4 << " " << -1*x << " safe\n";
	}
	/*for (int i=0;i<=20;i++) {
		for (int j=0;j<=20;j++) {
			cout << visited[i][j];
		}
		cout << "\n";
	}*/

	return 0;
}
