#include <bits/stdc++.h>
using namespace std;

 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s,g;int total=0,tempTotal=0;
    cin >> s;
    string arr[5]={"Clubs","Diamonds","Hearts","Spades"};
    vector <string> ar;
     for (int i=1;i<s.length();i++) {
        if (s[i]=='C' || s[i]=='D'||s[i]=='H'||s[i]=='S') {
                ar.push_back(g);
                g="";

            }
            else {
                g+=s[i];
            }
     }
     if (ar.size()<4) {
        ar.push_back(g);
     }
     cout << "Cards Dealt              Points" << endl;
     for (int j=0;j<ar.size();j++) {
            g=ar[j];
            cout << arr[j] << " ";
        for (int i=0;i<g.length();i++) {
            cout << g[i] << " ";
            if (g[i]=='A') {
                tempTotal+=4;
            }
            else if (g[i]=='K') {
                tempTotal+=3;
            }
            else if (g[i]=='Q') {
                tempTotal+=2;
            }
            else if (g[i]=='J') {
                tempTotal++;
            }
        }
        if (g.length()==0) {
            tempTotal+=3;
        }
        else if (g.length()==1) {
            tempTotal+=2;
        }
        else if (g.length()==2) {
            tempTotal++;
        }
        cout << " "<<tempTotal << endl;
        total+=tempTotal;
        tempTotal=0;
     }
     cout << "Total " << total << endl;

    return 0;
 }