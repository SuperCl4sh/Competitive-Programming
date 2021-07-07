//https://dmoj.ca/problem/interview2
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
 int main() {
    boost;
    int n;
    cin >> n;
    int ar[n];
    for (int i=0;i<n;i++) {
        cin >> ar[i];
    }
    int target;
    vector<vector<int>>found;
    vector<int>ans(3);
    sort(ar,ar+n);
    int ind;
    for (int i=0;i<n;i++) {
        for (int j=i+1;j<n;j++) {
            target=ar[i]+ar[j];
            auto it =upper_bound(ar,ar+n,target);
            ind=it-ar;
            if (ar[ind-1]!=target) continue;
            ans[0]=ar[i],ans[1]=ar[j],ans[2]=target;
            sort(ans.begin(),ans.end());
            if (found.size()==0) {
                found.pb(ans);
            }
            else {
                for (int i=0;i<found.size();i++) {
                    if (found[i]==ans) break;
                    if (i==found.size()-1) {
                        found.pb(ans);
                    }
                }
            }
    }
    }
    (found.size()==0)?cout<<-1<<"\n":cout<<found.size()<<"\n";
    return 0;
 }

