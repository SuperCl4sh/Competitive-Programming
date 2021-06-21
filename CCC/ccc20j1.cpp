#include <cstdio>
typedef long long ll;
using namespace std;
 int main() {
    int a,tot=0;
    for (int i=0;i<3;i++) {
        scanf("%i",&a);
        if (i==0) {
            tot+=a;
        }
        else if (i==1) {
            tot+=a*2;
        }
        else if (i==2) {
            tot+=a*3;
        }
    }
    if (tot>=10) {
        printf("happy\n");
    }
    else {
        printf("sad\n");
    }

    return 0;
 }