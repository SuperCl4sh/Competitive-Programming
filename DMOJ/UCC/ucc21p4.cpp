//https://dmoj.ca/problem/ucc21p4
#include <bits/stdc++.h>

using namespace std;
int dp[500005],dist[500005];bool inQueue[500005];

int fib(int n) {
	if (n==1) return 1;
	else if (n==2) return 1;
	else if (dp[n]!=-1) return dp[n];
	return dp[n]=(fib(n-1)+fib(n-2))%2021;
}

void solve(int stop) {
	queue<int>q;
	q.push(1);
	memset(dist,0x3f3f,sizeof(dist));
	int node;
	dist[1]=0;
	while (!q.empty()) {
		node=q.front();
		q.pop();
		inQueue[node]=0;
		if (node>dp[node]) {
			if (dist[node]+1<dist[node-dp[node]]) {
				dist[node-dp[node]]=dist[node]+1;
				
				if (!inQueue[node-dp[node]]) {q.push(node-dp[node]);inQueue[node-dp[node]]=1;}
			}
		}
		if (node+dp[node]<=stop) {
			if (dist[node]+1<dist[node+dp[node]]) {
				dist[node+dp[node]]=dist[node]+1;
				if (!inQueue[node+dp[node]]) {q.push(node+dp[node]);inQueue[node+dp[node]]=1;}
			}
		}
		if (node+1<=stop) {
			if (dist[node]+1<dist[node+1]) {
				dist[node+1]=dist[node]+1;
				if (!inQueue[node+1]) {q.push(node+1);inQueue[node+1]=1;}
			}
		}
		if (node>1) {
			if (dist[node]+1<dist[node-1]) {
				dist[node-1]=dist[node]+1;
				if (!inQueue[node-1]) {q.push(node-1);inQueue[node-1]=1;}
			}
		}
	}
	cout << dist[stop] << "\n";
	return;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	memset(dp,-1,sizeof(dp));
	int n;
	cin >> n;
	int res=fib(n);
	dp[1]=1,dp[2]=1;
	for (int i=1;i<=n;i++) {dp[i]+=i%50;}
	solve(n);

	return 0;
}
