#include <bits/stdc++.h>

using namespace std;

int main() {
long long x,y,maxX,maxY,currX=0,currY=0;
cin >> maxX >> maxY;
do {
  cin >> x >> y;
  currX+=x;
  currY+=y;
  currX=min(maxX,currX);
  currY=min(maxY,currY);
  currX=max(0LL,currX);
  currY=max(0LL,currY);
  if (x!=0|| y!=0) {
  cout << currX << " " << currY << endl;
  }
}while (x!=0 || y!=0);
return 0;

}