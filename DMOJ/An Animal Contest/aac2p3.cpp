//https://dmoj.ca/problem/aac2p3
#include <bits/stdc++.h>
using namespace std;
//#pragma GCC target ("avx2") #pragma GCC optimization ("O3") #pragma GCC optimization ("unroll-loops")
//^speed


//typedefs
typedef long long ll;
typedef string str;
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

//defines
#define mp make_pair
#define pb push_back
#define pf push_front
#define PF pop_front
#define PB pop_back
#define P push
#define F first
#define fr front()
#define bk back
#define S second
#define boost ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);srand(time(NULL))
#define PI 3.14159265
#define sz(s) (int)s.size()
#define sp(x) fixed << setprecision(x)
#define all(a) a.begin(),a.end()
#define mem(ar,a) memset(ar,a,sizeof(ar))
#define MT make_tuple
#define upper_bound ub
#define lower_bound lb
#define FOR(i,a,n,b) for (int i=a;i<n;i+=b)
#define rep(i,a,n) FOR (i,a,n,1)
#define ROF(i,a,n,b) for (int i=a;i>n;i-=b) 
#define vt vector
#define EACH(a,b) for (auto &a: b) 
#define mii map<int,int>
#define rtn return
#define gc getchar
#define each(a,b) for (auto a: b)
#define pc putchar

//constants
const ll MOD = 1000000007LL;
const ll MOD2=998244353LL;
const int INF=1<<30;

//input
template <typename T> void read(T& num) {
	num=0;
	register int c;
	c=gc();
	bool isNeg=0;
	if (c=='-') c=gc(),isNeg=1;
	for (;(c>47&&c<58); c=gc()) num=num*10+c-48;
	if (isNeg) num*=-1;

}
void read(str &s) {
	s="";
	char c;
	while((c=gc())&&(c!=-1&&c!='\n'&&c!='\r'&&c!=' ')) s+=c;

}
void read(ld &num) {
	str s="";
	read(s);
	num=stold(s);
}
void read(double &num) {
	str s="";
	read(s);
	num=stod(s);
	
}
void read(char &a) {
	a=gc();
}

template<typename A, typename B> void read(pair<A,B> &a) {
	read(a.F);
	read(a.S);
}
template <typename G> void read(vt<G>&ar) {
	EACH(a,ar) 
		read(a);

}
template <typename H, typename... Types> void read(H&  num, Types&... num1) {
	read(num);
	read(num1...);
}

//output
void out(int n) {
	if (n>9) out(n/10);
	pc(char((n%10)+'0'));
}

void out(ll n) {
	if (n>9) out(n/10LL);
	pc(char((n%10)+'0'));
}
void out(char c) {
	pc(c);
}
void out(str s) {
	rep(i,0,sz(s)) pc(s[i]);
}
void out (ld a) {
	str s=to_string(a);
	out(s);
}

void out(double a) {
	str s=to_string(a);
	out(s);
}
void out (const char *s) {
	
	rep (i,0,strlen(s)) {
		out(s[i]);
	}
}

template<typename T,typename M> void out(pair<T,M>a) {
	out(a.F);
	pc(' ');
	out(a.S);
}
template<typename T> void out(vt<T>ar) {
	rep (i,0,sz(ar)) {
		out(ar[i]);
		if (i+1<sz(ar)) pc(' ');

	}
}

template <typename h, typename... types> void out(h s, types... s1) {
	out(s);
	if (sizeof...(s1)) pc(' ');
	out(s1...);
}
void write() {}
template<typename v, typename... others> void write(v s, others... s1) {
	out(s);
	write(s1...);
}

template<typename T=ll,typename M=ll, typename S=ll> ll modmul(T a, M b, S m) {
	ll ans=a*b-m*ll(1.L/m*a*b);
	return ans+m*(ans<0)-m*(ans>=m);
}
template <typename T,typename S> ll Pow(T a, S b) {
	ll ret=1;
	while (b) {
		if (b&1) ret*=a;a*=a;b>>=1;
	}
	rtn ret;
}
template <typename T=ll, typename S, typename M> T Pow(T a, S b, M mod) {
	T ans=1;
	for (; b;a=modmul(a,a,mod),b/=2) {
		if (b&1) ans=modmul(ans,a,mod);
	}
	rtn ans;
}
template <typename A, typename B> A rando(A a, B b) { 
	return rand()%(b-a)+a;
}
void Time(clock_t start) {
	write("Process took ",(clock()-start)/double(CLOCKS_PER_SEC)," seconds.\n");
}
int dx8[8]={1,1,-1,-1,2,2,-2,-2},dy8[8]={2,-2,2,-2,1,-1,1,-1},dx4[4]={1,-1,0,0},dy4[4]={0,0,1,-1}; 
clock_t start;
/*--------------------------------------------------------------PROGRAM START-------------------------------------------------------------------------*/
vt<str>grid;
int n,m,psa[1505][1505];bool visited[1505][1505];

void init() {
	mem(psa,0);

	rep (i,1,m+1) psa[1][i]=(grid[0][i-1]=='X')+psa[1][i-1];
        rep (i,1,n+1) psa[i][1]=(grid[i-1][0]=='X')+psa[i-1][1];	

	rep (i,2,n+1) {
		rep (j,2,m+1) {
			psa[i][j]=psa[i-1][j]+psa[i][j-1]-psa[i-1][j-1]+(grid[i-1][j-1]=='X');
		}
	}
	rtn;
}

bool possib(int x) {
	mem(visited,0);
	queue<pair<pii,pii>>q;
	q.P(mp(mp(1,1),mp(x,x)));
	
	int x1,y1,x2,y2,x3,y3,x4,y4;
	while (!q.empty()) {
		x1=q.fr.F.F,y1=q.fr.F.S,x2=q.fr.F.F,y2=q.fr.S.S,x3=q.fr.S.F,y3=q.fr.F.S,x4=q.fr.S.F,y4=q.fr.S.S;
		q.pop();
		if (x1<1||y1<1||x2<1||y2<1||x3<1||y3<1||x4<1||y4<1||x1>n||x2>n||x3>n||x4>n||y1>m||y2>m||y3>m||y4>m||psa[x4][y4]-psa[x3][y3-1]-psa[x2-1][y2]+psa[x1-1][y1-1]) continue;
		else if (x4==n&&y4==m) rtn 1;
		else if (visited[x1][y1]) continue;
		visited[x1][y1]=1;
		rep (i,0,4) {
			int cx=dx4[i],cy=dy4[i];
			int nx1=x1+cx,ny1=y1+cy,nx4=x4+cx,ny4=y4+cy;
			if (!visited[nx1][ny1]) q.P(mp(mp(nx1,ny1),mp(nx4,ny4)));
		}
	}
	rtn 0;
	
}

int main() {
	boost;

	read(n);read(m);
	str s;
	rep (i,0,n) {
		read(s);
		grid.pb(s);
	}
	init();

	int left=0,right=1,mid;	

	rep (i,0,min(m,n)) {
		if (grid[0][i]=='X'||grid[i][0]=='X') break;
		++right;
	} 
	while (right-left>1) {
		mid=(left+right)/2;
		if (possib(mid)) left=mid;
		else right=mid;
	}
	out(left,'\n');


	rtn 0;
}
