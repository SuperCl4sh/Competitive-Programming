//https://dmoj.ca/problem/ecoo14r3p2
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;
typedef long double ld;
typedef unsigned long long ull;

 int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,sisters,cousins;str s,mother,grand;bool changed,broken;
    cin >> n;
    vector<vector<str>>names;
    vector<str>ar;
    vector<str>done;
    for (int i=0;i<n;i++) {
        cin >> s;
        ar.push_back(s);
        cin >> s;
        ar.push_back(s);
        names.push_back(ar);
        ar.clear();
    }
    for (int i=0;i<10;i++) {
        sisters=0;
        cousins=0;
        mother="";
        grand="";
        cin >> s;
        for (int f=0;f<names.size();f++) {
            if (!s.compare(names[f][1])) {
                mother=names[f][0];
                break;
            }
        }
        for (int f=0;f<names.size();f++) {
            if (!mother.compare(names[f][0])) {
                sisters++;
            }
        }
        if (sisters>0) sisters--;
        for (int f=0;f<names.size();f++) {
            if (names[f][1]==mother) {
                grand=names[f][0];
                break;
            }
        }
        done.clear();
        changed=1;
        while (changed) {
            broken=0;
            changed=0;
            for (int f=0;f<names.size();f++) {
                broken=0;
                if (names[f][0]==grand&&names[f][1]!=mother) {
                    for (int e=0;e<done.size();e++) {
                        if (done[e]==names[f][1]) {
                        broken=1;
                            break;
                        }
                    }
                    if (broken) continue;
                    for (int d=0;d<names.size();d++) {
                        if (names[d][0]==names[f][1]) {
                            cousins++;
                            changed=1;
                        }

                    }
                    done.push_back(names[f][1]);
                }
            }
        }
        cout << "Cousins: " << cousins << ", " << "Sisters: " << sisters << endl;


    }
    return 0;
 }
