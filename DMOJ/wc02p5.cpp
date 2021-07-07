//https://dmoj.ca/problem/wc02p5
#include <string>
#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
int main() {
    int n;int corrections;
    string word;
    vector <int> arr;
    cin >> n;
    for (int i=0;i<n+1;i++) {
        getline(cin,word);
        corrections=1;
        for (int a=0;a<word.length();a++) {
            if (word[a]=='(') {
                arr.push_back(1);
            }
            else if (word[a]==')') {
                arr.push_back(5);
            }
            else if (word[a]=='[') {
                arr.push_back(2);
            }
            else if (word[a]==']') {
                arr.push_back(6);
            }
            else if (word[a]=='<') {
                arr.push_back(3);
            }
            else if (word[a]=='>') {
                arr.push_back(7);
            }
            else if (word[a]=='{') {
                arr.push_back(4);
            }
            else if (word[a]=='}') {
                arr.push_back(8);
            }
        }
        while (corrections>0) {
                corrections=0;
        for (int f=1;f<arr.size();f++) {
            if (arr[f]-arr[f-1]==4){
                corrections++;
                arr.erase(arr.begin()+(f-1));
                arr.erase(arr.begin()+(f-1));
                for (int h=0;h<arr.size();h++) {
        }
            }
        }
        }
        if (arr.size()>0 && i>0) {
            cout << "FALSE" << endl;
        }
        else if (i>0){
            cout << "TRUE" << endl;
        }
        arr.clear();
    }
    return 0;
}

