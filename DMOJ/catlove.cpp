#include <string>
#include <iostream>
using namespace std;


 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,counter=0;string s;
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> s;
        if (s=="cats") {
            counter++;
        }
        else {
            counter--;
        }
    }
if (counter<0) {
cout << "dogs" << endl;
}
else if(counter>0) {
cout << "cats"<<endl;
}
else {
cout << "equal" << endl;
}
    return 0;
 }