//https://dmoj.ca/problem/ccc20s3
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
const ll MOD2 = 1000000009;
const ll high= (ll)(1e15);
const ll MOD3=998244353;
void read(auto &num) {register int Z;num=0;bool negat=0;Z=getchar();if (Z=='-') {negat=1;Z=getchar();}for(;(Z>47&&Z<58);Z=getchar()){num=num*10+Z-48;}if(negat){num*=-1;}}
int main() {
	boost;
	str a,b;
	ll prime=157,Hash,Hash2;
	cin >> a >> b;
	int freq[26];
	memset(freq,0,sizeof(freq));
	for (int i=0;i<sz(a);i++) {
		freq[a[i]-'a']++;
	}

	int currFreq[26];
	memset(currFreq,0,sizeof(currFreq));
	for (int j=0;j<sz(a);j++) {
		currFreq[b[j]-'a']++;
	}
	ll p_pow[sz(a)],P_Pow[sz(a)];
	p_pow[sz(a)-1]=prime;
	P_Pow[sz(a)-1]=prime;
	Hash=((ll)(b[sz(a)-1])*prime)%MOD;
	Hash2=((ll)(b[sz(a)-1])*prime)%MOD2;
	for (int i=sz(a)-2;i>=0;i--) {
		p_pow[i]=(p_pow[i+1]*prime)%MOD;
		P_Pow[i]=(P_Pow[i+1]*prime)%MOD2;
		Hash+=(((ll)(b[i]))*p_pow[i])%MOD;
		Hash2+=(((ll)(b[i]))*P_Pow[i])%MOD2;
		Hash%=MOD;
		Hash2%=MOD2;
	}
	set<tuple<ll,ll>>ans;
	for (int i=0;i<sz(b)-sz(a)+1;i++) {
		if (i>0) {
			currFreq[b[i-1]-'a']--;currFreq[b[i+sz(a)-1]-'a']++;
			Hash-=((((ll)(b[i-1]))*p_pow[0])%MOD);
			Hash+=MOD;
			Hash%=MOD;
			Hash+=((ll)(b[i+sz(a)-1]))%MOD;
			Hash%=MOD;
			Hash*=prime;
			Hash%=MOD;

			Hash2-=((((ll)(b[i-1]))*P_Pow[0])%MOD2);
			Hash2+=MOD2;
			Hash2%=MOD2;
			Hash2+=((ll)(b[i+sz(a)-1]))%MOD2;
			Hash2%=MOD2;
			Hash2*=prime;
			Hash2%=MOD2;
		}
		/*for (int j=0;j<26;j++) {
			for (int k=0;k<currFreq[j];k++) {
				cout << char(j+'a');
			}
		}
		cout << "\n";
		*/
		//cout << Hash << "\n";
		for (int k=0;k<26;k++) {
				if (freq[k]!=currFreq[k]) break;
				if (k==25) ans.insert(make_tuple(Hash,Hash2));
			}
	}
	cout << sz(ans) << "\n";
	return 0;
}
