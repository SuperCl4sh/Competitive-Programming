#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;
typedef long double ld;
typedef unsigned long long ull;


 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    str message,ans,c,g,s="11122233344455566667778888";int a;

    int ar[9];
    for (int i=0;i<9;i++) {
        cin >> a;
        ar[a-1]=i+1;
    }
    cin >> message;
    int index,secIndex;str last;
    for (int i=0;i<message.length();i++) {

        c=s[int(message[i])-'a'];
        index=int(message[i])-'a';
        secIndex=s.find_first_of(c);
        if (c==last) {
            ans+='#';
        }
        for (int f=min(index,secIndex);f<=max(secIndex,index);f++) {
            g=to_string(ar[stoi(c)]);
            ans+=g;
        }
        last=c;
    }
    cout << ans << endl;
    return 0;
 }