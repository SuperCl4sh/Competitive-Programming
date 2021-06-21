/*
ID: 
TASK: 
LANG: C++                 
*/

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
int main() {
    boost;
    str s;
    cin >> s;
    int a=0,b=0,c=0;
    for (int i=0;i<sz(s);i++) {
    	if (s[i]=='L') ++a;
	else if (s[i]=='M') ++b;
	else if (s[i]=='S') ++c;
    }
    int mCountInL=0,lCountInM=0,sCountInL=0,mCountInS=0,lCountInS=0,sCountInM=0;
    for (int i=0;i<a;i++) {
    	if (s[i]=='M') ++mCountInL;
	else if (s[i]=='S') ++sCountInL;
    }
    for (int j=a;j<a+b;j++) {
    	if (s[j]=='L') lCountInM++;
	else if (s[j]=='S') sCountInM++;
    }
    for (int j=a+b;j<sz(s);j++) {
    	//if (s[j]=='L') lCountInS++;
	if (s[j]=='M') mCountInS++;
    }
    //cout << lCountInS << "\n";
	cout << mCountInL+sCountInL+max(mCountInS,sCountInM) << "\n";    


    
    
    return 0;
}