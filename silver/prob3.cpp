#include <bits/stdc++.h>
#define int long long
using namespace std;

ifstream fin("mooyomooyo.in");
ofstream fout("mooyomooyo.out");

char grid[101][11];
bool vis[101][11];
int n,k;

set<pair<int,int>> idx;
int ccSize=0;

void floodfill(int i, int j, char x){
    if (vis[i][j] || i<0 || j <0 || i > n-1 || j > 9 || grid[i][j]!=x) {
      return;
    }
    // if (i<0 || j <0 || i > n-1 || j > 9 || vis[i][j] || grid[i][j]!='x') {
    //   return;
    // }
    vis[i][j]=true;
    if (grid[i][j]==x) {
      ccSize++;
    }
    floodfill(i+1,j,x);
  floodfill(i-1,j,x);floodfill(i,j+1,x);floodfill(i,j-1,x);
    //idx.insert({i,j});
}
void floodfill2(int i, int j, char x){
  if (vis[i][j] || i<0 || j <0 || i > n-1 || j > 9 || grid[i][j]!=x) {
    return;
  }
  vis[i][j]=true;
  if (grid[i][j]==x) {
    grid[i][j]='0';
  }
  floodfill2(i+1,j,x);
  floodfill2(i-1,j,x);floodfill2(i,j+1,x);floodfill2(i,j-1,x);
  //idx.insert({i,j});
}

void gravity() {
  for (int x=0 ; x<=9 ; x++) {
    string s;
    int first=-1;
    for (int i=0 ; i < n ; i++) {
      if (grid[i][x]!='0' && first==-1) {
        first=i;
      }
    }
    if (first==-1) {
      continue;
    }
    for (int i=first ; i < n ;i++) {
      if (grid[i][x]!='0') {
        s+=grid[i][x];
      }
    }
    string f(n-s.size(),'0');
    f+=s;
    for (int i=0 ; i < n ; i++) {
      grid[i][x]=f[i];
    }
  }

}

//bool flag=false;
bool solve(char x) {
  bool flag=false;
  for (int i=0 ; i < n ; i++) {
    for (int j=0 ; j < 10 ; j++) {
      if (!vis[i][j] && grid[i][j]==x) {
        ccSize=0;

        floodfill(i,j,x);

        //ccSize=0;
        //memset(vis,false,sizeof(vis));
        if (ccSize>=k) {
          flag=true;
          memset(vis,false,sizeof(vis));
          floodfill2(i,j,x);
        }
      }
    }
  }
  ccSize=0;
  memset(vis,false,sizeof(vis));
  return flag;
}

bool solve2(char x) {
  bool flag=false;
  for (int i=0 ; i < n ; i++) {
    for (int j=0 ; j < 10 ; j++) {
      if (!vis[i][j] && grid[i][j]==x) {
        ccSize=0;

        floodfill(i,j,x);

        //ccSize=0;
        //memset(vis,false,sizeof(vis));
        if (ccSize>=k) {
          ccSize=0;
          memset(vis,false,sizeof(vis));
          return true;
        }
      }
    }
  }
  ccSize=0;
  memset(vis,false,sizeof(vis));
  return flag;
}
signed main() {
    fin >> n >> k;
    for(int i=0 ; i < n ; i++){
      for(int j=0 ; j < 10 ; j++){
        fin >> grid[i][j];
      }
    }
  bool f1=true,f2=true,f3=true,f4=true,f5=true,f6=true,f7=true,f8=true,f9=true;
  bool g1=true,g2=true,g3=true,g4=true,g5=true,g6=true,g7=true,g8=true,g9=true;

  int times=0;
  while (g1||g2||g3||g4||g5||g6||g7||g8||g9) {

    //times++;
    f1=solve('1');
    f2=solve('2');
    f3=solve('3');
    f4=solve('4');
    f5=solve('5');
    f6=solve('6');
    f7=solve('7');
    f8=solve('8');
    f9=solve('9');
    //flag=false;
    gravity();
    g1=solve2('1');
    g2=solve2('2');
    g3=solve2('3');
    g4=solve2('4');
    g5=solve2('5');
    g6=solve2('6');
    g7=solve2('7');
    g8=solve2('8');
    g9=solve2('9');
  }
  //gravity();
  // f1=solve('1');
  // f2=solve('2');
  // f3=solve('3');
  // f4=solve('4');
  // f5=solve('5');
  // f6=solve('6');
  // f7=solve('7');
  // f8=solve('8');
  // f9=solve('9');
  // gravity();
    // for(auto it : idx){
    //   int x=it.first, y=it.second;
    //   grid[x][y]='0';
    // }
  //gravity();
    for(int i=0 ; i < n ; i++){
      for(int j=0 ; j <10 ; j++){
        fout << grid[i][j];
      }
      fout << endl;
    }
}