#include <bits/stdc++.h>

#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
using namespace std;
//ofstream fout (".out");
//ifstream fin (".in");
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
const ll MOD = 1000000007;
const ll high= (ll)(1e15);
const ll MOD2 = 998244353;
void read(auto &num) {register int Z;num=0;bool negat=0;Z=getchar();if (Z=='-') {negat=1;Z=getchar();}for(;(Z>47&&Z<58);Z=getchar()){num=num*10+Z-48;}if(negat){num*=-1;}}
void Read(auto &num) {register int Z;num=0;bool negat=0;Z=getchar_unlocked();if (Z=='-') {negat=1;Z=getchar_unlocked();}for(;(Z>47&&Z<58);Z=getchar_unlocked()){num=num*10+Z-48;}if(negat){num*=-1;}}
ll modmul(ll a, ll b, ll m) {ll ans=a*b-m*ll(1.L/m*a*b);return ans+m*(ans<0)-m*(ans>=m);}
ll Pow(ll a, ll b, ll mod) {ll ans=1;for (; b;a=modmul(a,a,mod),b/=2) {if (b&1) ans=modmul(ans,a,mod);}return ans;}
void Print(auto &temp) {for (auto x: temp) cout << x << " ";cout << "\n";return;}
vector<vll>ar;
ll change=1000000LL,mod1=20000001LL;
vector<str>split(str s) {
	vector<str>ret;
	str curr="";
	for (int i=0;i<sz(s);i++) {
		if (s[i]==' ') {
			if (!curr.empty()) ret.pb(curr);
			curr="";
		}
		else curr+=s[i];
	}
	if (!curr.empty()) ret.pb(curr);
	return ret;
}
bool good(ll a, ll b, ll c) {
	if (c-b==b-a) return 1;
	return 0;
}
bool valid(vector<vll>ar) {
	if (!good(ar[0][0],ar[0][1],ar[0][2])||!good(ar[1][0],ar[1][1],ar[1][2])||!good(ar[2][0],ar[2][1],ar[2][2])||!good(ar[0][0],ar[1][0],ar[2][0])||!good(ar[0][1],ar[1][1],ar[2][1])||!good(ar[0][2],ar[1][2],ar[2][2])) return 0;
	return 1;
}
vector<vector<ll>>ans;
set<vector<vll>>visited;
void solve(vector<vll>ar,vector<vector<bool>>bad) {
		if (visited.find(ar)!=visited.end()) return;
		visited.insert(ar);
		if (!ans.empty()) return;
		bool done=0;ll start,start2;
		vector<vll>Start;
		for (int i=0;i<3;i++) {
			for (int j=0;j<3;j++) {
				done=0;
			if (bad[i][j]) {
				start=high,start2=high;
				if (j==0) {
					if (!bad[i][j+1]&&!bad[i][j+2]) {
						bad[i][j]=0;
						ar[i][j]=ar[i][j+1]-(ar[i][j+2]-ar[i][j+1]);
						start=ar[i][j];
						done=1;
					}
				}
				else if (j==1) {
					if (!bad[i][j-1]&&!bad[i][j+1]) {
						bad[i][j]=0;
						ar[i][j]=ar[i][j-1]+((ar[i][j+1]-ar[i][j-1])/2);
						start=ar[i][j];
						done=1;
					}
				}
				else if (j==2) {
					if (!bad[i][j-1]&&!bad[i][j-2]) {
						bad[i][j]=0;
						ar[i][j]=ar[i][j-1]+(ar[i][j-1]-ar[i][j-2]);
						start=ar[i][j];
						done=1;
					}
				}
				if (i==0) {
					if (!bad[i+1][j]&&!bad[i+2][j]) {
						bad[i][j]=0;
						ar[i][j]=ar[i+1][j]-(ar[i+2][j]-ar[i+1][j]);
						start2=ar[i][j];
					}
				}
				else if (i==1) {
					if (!bad[i-1][j]&&!bad[i+1][j]) {
						bad[i][j]=0;
						ar[i][j]=((ar[i+1][j]-ar[i-1][j])/2LL)+ar[i-1][j];
						start2=ar[i][j];
					}
				}
				else if (i==2) {
					if (!bad[i-2][j]&&!bad[i-1][j]) {
						bad[i][j]=0;
						ar[i][j]=ar[i-1][j]+(ar[i-1][j]-ar[i-2][j]);
						start2=ar[i][j];
					}
				}
				//if (start!=high&&start2!=high&&start!=start2) {return;}
			}
			}
		}
		bool broken=0;int counter=0;
		for (int i=0;i<3;i++) {
			for (int j=0;j<3;j++) {
				if (bad[i][j]) {broken=1;++counter;}
			}
		}
		if (!broken) {
			if (valid(ar)) {
				for (int i=0;i<3;i++) {
					vll temp;
					for (int j=0;j<3;j++) {
						temp.pb(ar[i][j]);
					}
					ans.pb(temp);
				}
			}
			return;
		}
		if (counter==1) {
			solve(ar,bad);
			return;
		}
		Start=ar;
		for (int i=0;i<3;i++) {
			for (int j=0;j<3;j++) {
				if (bad[i][j]) {
					ll a=ll(rand())%mod1-change;
					bad[i][j]=0;
					ar[i][j]=a;
					solve(ar,bad);
					ar=Start;
					if (!ans.empty()) return;
					ar[i][j]=high;
					bad[i][j]=1;
				}
			}
		}
		solve(ar,bad);
		return;


}
int main() {
    boost;
    srand(time(0));
    vector<vector<bool>>bad;
    vector<vll>ar;
    str s,target="X";
    for (int i=0;i<3;i++) {
	getline(cin,s);
	vector<str>temp=split(s);
	vll temp2;
	vector<bool>badTemp;
	for (int j=0;j<sz(temp);j++) {
		if (temp[j]==target) {temp2.pb(high);badTemp.pb(1);}
		else {badTemp.pb(0);temp2.pb(stoll(temp[j]));}
	}
	bad.pb(badTemp);
	ar.pb(temp2);
    }
    solve(ar,bad);
    for (int i=0;i<3;i++) {
	    for (int j=0;j<3;j++) {
		    if (j==2) cout << ans[i][j];
		    else cout << ans[i][j] << " ";
	    }
	    cout << "\n";
    }
    
    return 0;
}