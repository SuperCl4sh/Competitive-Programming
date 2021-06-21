//https://dmoj.ca/problem/ccc13s3
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
int t,ans=0;
vector<vector<int>>done;
void solve(bool ar[10][10],int total[7],vector<int>moves) {
bool changed=0;

for (int i=1;i<=4;i++) {
    for (int j=i+1;j<=4;j++) {
        if (ar[i][j]==0) {
            ar[i][j]=1,ar[j][i]=1;
            total[i]+=3;
            moves.pb(i);
            solve(ar,total,moves);
            moves[moves.size()-1]=j;
            total[i]-=3,total[j]+=3;
            solve(ar,total,moves);
            total[j]-=2,total[i]++;
            moves[moves.size()-1]=0;
            solve(ar,total,moves);
            total[j]--,total[i]--;
            moves.erase(moves.begin()+moves.size()-1);
            ar[i][j]=0,ar[j][i]=0;
            changed=1;
            return;
        }
    }
}
//printf("%i %i %i %i\n",total[1],total[2],total[3],total[4]);
if (changed) return;
for (int i=0;i<done.size();i++) {
    if (done[i]==moves) return;
}
    for (int i=1;i<=4;i++) {
        if (i==t) continue;
        if (total[i]>=total[t]) return;
    }
done.pb(moves);
return;
}
 int main() {
    boost;
    int a,b,c,d,g;
    cin >> t >> g;
    bool ar[10][10];int tot[7];
    for (int i=0;i<10;i++) {
        for (int j=0;j<10;j++) {
            ar[i][j]=0;
        }
    }
    memset(tot,0,sizeof(tot));
    for (int i=0;i<g;i++) {
        cin >> a >> b>> c >> d;
        ar[a][b]=1,ar[b][a]=1;
        if (c>d) {
            tot[a]+=3;

        }
        else if (d>c) {
            tot[b]+=3;
        }
        else {
            tot[a]++,tot[b]++;
        }
    }
    vector<int>moves;
    solve(ar,tot,moves);
    cout << done.size() << "\n";
    return 0;
 }
