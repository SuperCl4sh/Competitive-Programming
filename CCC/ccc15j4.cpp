//https://dmoj.ca/problem/ccc15j4
#include <bits/stdc++.h>
using namespace std;

 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,b,time=0;char a;
    cin >> n;
    int totTime[101];
    int wait[101];
    int rep[101];
    for (int i=0;i<sizeof(totTime)/sizeof(totTime[0]);i++) {
        totTime[i]=0;
        wait[i]=0;
        rep[i]=-1;
    }
    for (int i=0;i<n;i++) {
        cin >> a >> b;
        if (a=='W') {
            time+=b-2;
        }
        else {
            if (a=='R') {
                wait[b]=time;
                rep[b]=2;
            }
            else {
                totTime[b]+=time-wait[b];
                //cout << b << " " << time << " " << wait[b] << endl;
                wait[b]=0;
                rep[b]=1;
            }

        }
        time++;

    }
    for (int i=1;i<sizeof(totTime)/sizeof(totTime[0]);i++) {
        if (rep[i]==1) {
            cout << i << " " <<totTime[i] << endl;
        }
        else if (rep[i]==2){
            cout << i << " "<<-1 << endl;
        }
    }
    return 0;
 }
