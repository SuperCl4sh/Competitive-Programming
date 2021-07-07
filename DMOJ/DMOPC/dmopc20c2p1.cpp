//https://dmoj.ca/problem/dmopc20c2p1
#include <bits/stdc++.h>
using namespace std;
 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,row=2000,col=0,startRow=-1,endRow=0,rowIncrease=0;string s;
    cin >> n;
    cin >> s;
    char ar[5000][n+1];
    for (int i=0;i<5000;i++) {
        for (int j=0;j<n;j++) {
            ar[i][j]='.';
        }
    }
    for (int i=0;i<s.length();i++) {
        if (s[i]=='v') {
            row++;
            ar[row][col]='\\';
            col++;
            rowIncrease++;
        }
        else if(s[i]=='^') {
            ar[row][col]='/';
            col++;
            row--;
        }
        else if (s[i]=='>') {
            ar[row][col]='_';
            col++;
        }
        col=min(col,n);
    }
    for (int v=0;v<5000;v++) {
        for (int j=0;j<n;j++) {
            if (ar[v][j]!='.') {
                if (startRow==-1) {
                    startRow=v;
                    break;
                }
                else if (startRow!=-1) {
                    endRow=v;
                    break;
                }
            }
        }
    }
    if (!endRow) {
        endRow=startRow+rowIncrease;
    }
    startRow=max(startRow,0);
    for (int j=startRow;j<=endRow;j++) {
        for (int k=0;k<n;k++) {
            cout << ar[j][k];
        }
        cout << endl;
    }
    return 0;
 }

