#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define pf push_front
#define PF pop_front
#define PB pop_back
#define P push
#define F first
#define S second
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define make_tuple MT
#define PI 3.14159265
typedef long long ll;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;
typedef pair<double,double>pdd;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ld,ld>pld;
typedef pair<str,str>pss;
char _;
const int MOD = 1000000007;
str ans="";
void solve () {
ans="";
int n,a;
cin >> n;

deque<int>q,dq,s;
for (int i=0;i<n;i++) {	
	cin >> a;
	q.pf(a);
	s.pf(a);
}
while (!q.empty()) {
	if (dq.size()==0) {
		dq.pb(q.front());
		q.PF();
		continue;
	}
	if (dq.front()-1==q.front()) {
		dq.pf(q.front());
		q.PF();
	}
	else if (dq.front()-1==q.back()) {
		dq.pf(q.back());
		q.PB();
	}
	else if (dq.back()+1==q.front()) {
		dq.pb(q.front());
		q.PF();
	}
	else if (dq.back()+1==q.back()) {
		dq.pb(q.back());
		q.PB();
	}
	else {ans="no";break;}


}

while (!dq.empty()) dq.PF();
if (ans=="no") {
	while (!s.empty()) {
	if (dq.size()==0) {
		dq.pb(s.back());
		s.PB();
		continue;
	}
	if (dq.front()-1==s.front()) {
		dq.pf(s.front());
		s.PF();
	}
	else if (dq.front()-1==s.back()) {
		dq.pf(s.back());
		s.PB();
	}
	else if (dq.back()+1==s.front()) {
		dq.pb(s.front());
		s.PF();
	}
	else if (dq.back()+1==s.back()) {
		dq.pb(s.back());
		s.PB();
	}
	else {return;}


}
}
ans="yes";


}
 int main() {
    boost;
    int n,i=1;
    cin >> n;
    while (n--) {
	solve();
    	cout << "Case #" << i << ": " << ans << "\n"; 
    ++i;
    }
    return 0;
 }