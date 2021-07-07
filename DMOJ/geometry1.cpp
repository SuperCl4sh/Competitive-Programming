//https://dmoj.ca/problem/geometry1
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
 int main() {
    boost;
    int n;double a,b,c,d,e,f,s1,s2,s3,p,A;
    cin >> n;
    while (n--) {
        cin >> a >> b >> c >> d >> e >> f;
        s1=pow(pow(c-a,2)+pow(d-b,2),0.5);
        s2=pow(pow(e-a,2)+pow(f-b,2),0.5);
        s3=pow(pow(e-c,2)+pow(f-d,2),0.5);
        p=(s1+s2+s3)/2;
        A=sqrt(p*(p-s1)*(p-s2)*(p-s3));
        cout << fixed<<setprecision(2)<<A<<" "<<p*2.0<<"\n";
    }
    return 0;
 }

