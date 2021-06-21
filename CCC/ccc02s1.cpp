#include <bits/stdc++.h>
using namespace std;
int p,g,r,o,comb=0,small=INT_MAX;int done[10000][5];
void solve (int total, int P, int G, int R, int O) {
if (total==0) {
    for (int i=0;i<sizeof(done)/sizeof(done[0]);i++) {
        if (done[i][0]==P && done[i][1] ==G && done[i][2]==R && done[i][3]==O) {
            return;
        }
        else if (done[i][0]==-1 && done[i][1] ==-1 && done[i][2]==-1 && done[i][3]==-1) {
            done[i][0]=P,done[i][1]=G,done[i][2]=R,done[i][3]=O;
            break;
        }
    }
    printf("# of PINK is %i # of GREEN is %i # of RED is %i # of ORANGE is %i\n",P,G,R,O);
    small=min(small,P+G+R+O);
    comb++;
    return;
}
else if (total<0) return;
if (total-p>=0) {
    solve(total-p,P+1,G,R,O);
}
if (total-g>=0) {
    solve (total-g,P,G+1,R,O);
}
if (total-r>=0) {
    solve(total-r,P,G,R+1,O);
}
if (total-o>=0) {
    solve(total-o,P,G,R,O+1);
}
return;


}
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int cost;
    for (int i=0;i<sizeof(done)/sizeof(done[0]);i++) {
        done[i][0]=-1,done[i][1]=-1,done[i][2]=-1,done[i][3]=-1;
    }
    cin >> p >> g >> r >> o >> cost;
    solve(cost,0,0,0,0);
    printf("Total combinations is %i.\n",comb);
    printf("Minimum number of tickets to print is %i.\n",small);
    return 0;
 }