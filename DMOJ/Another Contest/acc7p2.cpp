//https://dmoj.ca/problem/acc7p2
#include <bits/stdc++.h>

using namespace std;
int n;
void Print(int ar[]) {
	for (int i=0;i<n;i++) {	
		cout << ar[i];
		if (i+1<n) cout << " ";
		else cout << endl;
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	srand(time(NULL));
	cin >> n;
	int ar[n],a;
	for (int i=1;i<=n;i++) ar[i-1]=i;
	while (1) {
		Print(ar);
		cin >> a;
		if (!a) break;
		--a;
		swap(ar[a],ar[rand()%n]);


		
	}


	return 0;
}
