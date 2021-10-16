#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define sz(s) (int)s.size()
#define all(a) a.begin(),a.end()
const char nl = '\n';

int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	int N;cin >> N;
	vector<int>ar(N);for (auto &x: ar) cin >> x;
	if (is_sorted(all(ar))) {
		cout << 0 << nl;
		return 0;
	}
	vector<int>secondStack,moves,start=ar;
	while (!ar.empty()) {
		int curr=ar.front();ar.erase(ar.begin());
		if (secondStack.empty()) {
			secondStack.insert(secondStack.begin(),curr);
			moves.pb(1);
		}
		else if (sz(secondStack)==1) {
			if (curr>secondStack.front()) {
				secondStack.pb(curr);
				moves.pb(-1);
				moves.pb(2);
			}
			else {
				secondStack.insert(secondStack.begin(),curr);
				moves.pb(1);
			}
		}
		else if (curr>=secondStack.back()) {
			moves.pb(-sz(secondStack));moves.pb(sz(secondStack)+1);
			secondStack.pb(curr);
		}
		else {
			int pos=sz(secondStack);
			for (int i=0;i<sz(secondStack);i++) {
				if (secondStack[i]>curr) {
					pos=i+1;
					break;
				}
			}
			assert(is_sorted(all(secondStack)));
			if (pos>1) {
				moves.pb(-pos+1);moves.pb(pos);
			}
			else moves.pb(1);
			secondStack.insert(secondStack.begin()+pos-1,curr);
		}
	}
	//for (int i=0;i<N;i++) cout << secondStack[i] << " \n"[i==N-1];
	assert(is_sorted(all(secondStack)));
	moves.pb(-N);
	cout << sz(moves) << nl;
	for (auto &move: moves) cout << move << nl;
	ar=start;
	secondStack.clear();
	for (auto &move: moves) {
		assert(move!=0);
		if (move>0) {
			secondStack.insert(secondStack.begin(),ar.begin(),ar.begin()+move);
			ar.erase(ar.begin(),ar.begin()+move);
		}
		else {
			move*=-1;
			ar.insert(ar.begin(),secondStack.begin(),secondStack.begin()+move);
			secondStack.erase(secondStack.begin(),secondStack.begin()+move);
		}
	}
	assert(is_sorted(all(ar)));
	//for (auto &x: ar) cout << x << " ";
	//cout << nl;
	return 0;
}
