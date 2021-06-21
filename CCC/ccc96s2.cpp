#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define F first
#define S second
typedef long long ll;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;
typedef pair<double,double>pdd;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ld,ld>pld;
vector<int>ar;

str digit,ans;int currDig,ind;
void solve (str s) {
ar.clear();
for (int i=0;i<s.length();i++) {
    digit=s[i];
    ar.pb(stoi(digit));
}
while (ar.size()>2) {
    for (int i=0;i<ar.size();i++) {
        cout << ar[i];
    }
    cout << endl;
    currDig=ar[ar.size()-1];
    ar.erase(ar.begin()+ar.size()-1);
    if (currDig) {
        if (ar[ar.size()-1]>=currDig) {
            ar[ar.size()-1]-=currDig;
        }
        else {
            ind=ar.size()-2;
            while (ar[ind]==0) {
                ind--;
            }
            ar[ind]--;
            for (int i=ind+1;i<ar.size()-1;i++) {
                ar[i]+=9;
            }
            ar[ar.size()-1]+=10;
            ar[ar.size()-1]-=currDig;
            while (true) {
                if (ar[0]==0) {
                    ar.erase(ar.begin());
                }
                else {
                    break;
                }
            }
        }
    }


}
for (int i=0;i<ar.size();i++) {
    cout << ar[i];
}
cout << endl;
if (ar.size()==2) {
if ((10*ar[0]+ar[1])%11==0) cout << "The number "+s+" is divisible by 11." << endl;
else cout << "The number " + s +" is not divisible by 11." << endl;
}
else {
   if ((10*ar[0])%11==0) cout << "The number "+s+" is divisible by 11." << endl;
else cout << "The number " + s +" is not divisible by 11." << endl;
}
return;
}

 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    str s;
    for (int i=0;i<n;i++) {
        cin >> s;
        solve(s);
        if (i+1<n) cout << endl;
    }
    return 0;
 }