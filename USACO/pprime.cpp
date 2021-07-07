/*
ID: 
TASK: pprime
LANG: C++                 
*/
#include <bits/stdc++.h>
#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
using namespace std;
ofstream fout ("pprime.out");
ifstream fin ("pprime.in");
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
set<int>palin;
bool prime(int n) {
	for (int i=3;i<=(int)(sqrt(n));i++) {
		if (n%i==0) return 0;
	}
	return 1;
}
int total(int n) {
	return sz(to_string(n));
}
int main() {
    boost;
    int a,b;
    fin >> a >> b;
    int endDigits=total(b),digits=0;
    queue<int>q;
    for (int i=0;i<=9;i++) {
    	q.P(i);
	if (i>0) q.P(11*i);
    }
    int curr;
    while (!q.empty()) {
    	curr=q.front();
	q.pop();
	if (curr>b) continue;
	else if (curr>=a&&(curr&1)) palin.insert(curr);
	digits=total(curr);
	for (int i=1;i<=9;i++) {
		for (int j=1;j<=(endDigits-digits)/2;j++) {
			q.P((curr*pow(10,j)+i)+(i*pow(10,2*j-1+digits))); 
		}
	}
    }
    
    for (auto it=palin.lower_bound(a);it!=palin.end();++it) {
    	curr=*it;
	if (curr>b) break;
	if (prime(curr)) fout << curr << "\n";	
    }
    
    
    
    return 0;
}
//this took longer than i'm willing to admit .-.

