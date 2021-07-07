//https://dmoj.ca/problem/ccc01s3
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
using namespace std;
#define mp make_pair
#define pb push_back
#define pf push_front
#define PF pop_front
#define PB pop_back
#define P push
#define F first
#define S second
#define scann(speed){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}speed=s*f;}
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define make_tuple MT
#define PI 3.14159265
#define len(s) (int)s.length()
#define sz(s) (int)s.size()
#define sp(x) fixed << setprecision(x)
typedef long long ll;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;
typedef pair<double,double>pdd;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ld,ld>pld;
typedef pair<str,str>pss;
typedef pair<char,char>pcc;
typedef pair<long,long>pl;
char _;
const ll MOD = 1000000007;
const ll mxN= (ll)(1e15);
void read(auto &num) {register int Z;num=0;bool negat=0;Z=getchar();if (Z=='-') {negat=1;Z=getchar();}for(;(Z>47&&Z<58);Z=getchar()){num=num*10+Z-48;}if(negat){num*=-1;}}
vector<vector<int>>adj(26);
bool visited[26],done=0,completed[27][27];int f,g;
vector<pii>ans;
void dfs(int node) {
if (node==1) {bool done=1;return;}
if (visited[node]) return;
visited[node]=1;
for (auto x: adj[node]) {
	if (node==f&&x==g) continue;
	else if (node==g&&x==f) continue;
	else if (x==1) {done=1;return;}
		dfs(x);
}
return;
}
int main() {
    boost;
    char a,b;
    while (true) {
    	cin >> a >> b;
	if (a=='*') break;
	adj[a-'A'].pb(b-'A');adj[b-'A'].pb(a-'A');
    }
    for (int i=0;i<26;i++) {
	    for (int j=0;j<sz(adj[i]);j++) {
		if (completed[i][adj[i][j]]||completed[adj[i][j]][i]) continue;
	completed[i][adj[i][j]]=1;completed[adj[i][j]][i]=1;	
	    	f=i;g=adj[i][j];done=0;
		memset(visited,0,sizeof(visited));
		dfs(0);
		if (!done) {
			ans.pb(mp(f,g));
		} 
	    }
    }
    if (sz(ans)==0) printf("There are 0 disconnecting roads.\n");
    else {
	    printf("There are %i disconnecting roads.\n",sz(ans));
	    for (int i=0;i<sz(ans);i++) {
	    	cout << char(ans[i].F+'A') << char(ans[i].S+'A') << "\n";
	    }
    	}
    return 0;
}

