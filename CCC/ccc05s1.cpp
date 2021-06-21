//https://dmoj.ca/problem/ccc05s1
#include <bits/stdc++.h>
using namespace std;
int j,counter;
string g,h;
int arr[26]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
void solve (string s){
    j=0,counter=0;
    g="";
    for (int i=0;i<s.length();i++) {
        if (j>=10) break;
        else if (isalpha(s[i])) {
            cout << arr[(int)s[i]-65];
            j++;
        }
        else if (isdigit(s[i])) {
            cout << s[i];
            j++;
        }
        if (j==3 && counter==0) {
            cout << "-";
            counter++;
        }
        else if (j==6 && counter==1) {
                counter++;
                cout << "-";
        }
    }
    cout << endl;
    return;

}
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;string s;
    cin >> n;
    while (n--) {
        cin >> s;
        solve(s);
    }
    return 0;
 }
