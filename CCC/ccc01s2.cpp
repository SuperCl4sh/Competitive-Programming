//https://dmoj.ca/problem/ccc01s2
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
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
typedef pair<long,long>pl;
char _;
const int MOD = 1000000007;
int ar[1000][1000];
int main() {
    boost;
    int x,y;
    cin >> x >> y;
    if (x==y) {cout << x <<"\n";return 0;}
    int curr=x,r=100,c=100,counter=1;
    ar[r][c]=x,ar[r+1][c]=x+1;
    r++,c++,curr+=2;
    while (curr<=y) {
	    while (curr<=y) {
	    	if (counter==2) {
			if (ar[r][c-1]!=0) {
				ar[r][c]=curr;
				r--;
			}
			else break;
		}
		else if (counter==4) {
			if (ar[r][c+1]!=0) {
				ar[r][c]=curr;
				r++;
			}
			else break;
		}
		else if (counter==1) {
			if (ar[r-1][c]!=0) {
				ar[r][c]=curr;
				c++;
			}
			else break;
		}
		else if (counter==3) {
			if (ar[r+1][c]!=0) {
				ar[r][c]=curr;
				c--;
			}
			else break;
		}
		
		++curr;
	    
	    }
	    counter++;
	    if (counter==5) counter=1;
    }
    int sr=-1,sc=-1,Sr=-1,Sc=-1,len=0,currlen;
    for (int i=0;i<750;i++) {
	   currlen=0;
    	for (int j=0;j<750;j++) {
		if (ar[i][j]!=0) {
			if (sr==-1) {sr=i;sc=j;}
			Sr=i;Sc=j;
			currlen++;
		}
		
	}
	len=max(currlen,len);
    }
    bool gone=0;
    len--;
    int current=x;
    if (Sr==-1) {cout << ar[sr][sc] << "\n";return 0;}
    for (int i=sr;i<=Sr;i++) {
	gone=0;
    	for (int j=Sc-len;j<=Sc+len;j++) {
		if (ar[i][j]==0&&current==x) cout << "   ";
		else if (ar[i][j]!=0){
			if (ar[i][j]/10==0) cout << " " << ar[i][j] << " ";
			else cout << ar[i][j] << " ";
			++current;
			gone=1;
		}	
	}
	if (gone) cout << "\n";
    }
    
    return 0;
 }
