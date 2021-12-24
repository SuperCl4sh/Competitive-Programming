#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
    //ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<array<int, 3>>ar(N + 1); for (int i = 1; i <= N; i++) cin >> ar[i][0], ar[i][1] = i, ar[i][2] = 0; // 0 is right, 1 is left
        vector<array<int, 2>>copy(N + 1); for (int i = 1; i <= N; i++) for (int j = 0; j < 2; j++) copy[i][j] = ar[i][j];
        sort(1 + all(copy));
        for (int i = 1; i <= N; i++) {
            if (copy[i][1] == i) continue;
            for (int j = 0; j < 2; j++) swap(ar[i][j], ar[copy[i][1]][j]);
            if (abs(i - copy[i][1]) % 2) ar[i][2] ^= 1, ar[copy[i][1]][2] ^= 1;
            swap(copy[i], copy[inds[i]]);
        }
        //for (int i = 1; i <= N; i++) cout << ar[i][0] << " \n"[i == N];
        bool ok = 1;
        for (int i = 1; i <= N && ok; i++) {
            if (ar[i][2] == 0) continue;
            int tot = 0;
            while (i + tot + 1 <= N && ar[i + tot][2]) tot++;
            ok = !(tot % 2);
            i += tot;
        }
        cout << ((ok) ? "YES" : "NO") << nl;
    }
    return 0;
}
