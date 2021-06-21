#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int a,b,c,d,tot=0;
    cin >> a >> b>> c >> d;
    for (int i=0;i<1000;i++) {

        if (i*a>d) {
            break;
        }


        for (int j=0;j<1000;j++) {
                if (i*a+j*b>d) {
                break;
                }


            for (int k=0;k<1000;k++) {
                if (i>0 || j>0 || k>0) {
                if (i*a+b*j+c*k<=d) {
                    printf("%i Brown Trout, %i Northern Pike, %i Yellow Pickerel\n",i,j,k);
                    tot++;
                }

                }

                else if (k>0){
                    break;
                }

            }
        }
    }
    printf("Number of ways to catch fish: %i",tot);
    return 0;
 }