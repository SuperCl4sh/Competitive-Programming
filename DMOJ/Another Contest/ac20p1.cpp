#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PI 3.14159265
int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;long double a,b,c;
	cin >> t;
	for (int i=0;i<t;i++) {
		cin >> a >> b >> c;
		long double A=pow(a,2LL),B=pow(b,2LL),C=pow(c,2LL);
		if (A+B==C||B+C==A||A+C==B) {
			cout << "R\n";
			continue;
		}
		long double angle1=((acos((C-A-B)/(-2*a*b)))*180.0)/PI;
		long double angle2=((acos((A-B-C)/(-2*b*c)))*180.0)/PI;
		long double angle3=180-angle1-angle2;
		if (angle1>90||angle2>90||angle3>90) {
			cout << "O\n";
			continue;
		}
		cout << "A\n";
	}
	
	return 0;

}