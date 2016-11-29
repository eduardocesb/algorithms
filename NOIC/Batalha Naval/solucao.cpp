#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
char mapa[110][110];

void tiro(int X, int Y){
   if(mapa[X][Y] == '#'){
      mapa[X][Y] = '.';
      if((Y+1<=M+1) && (mapa[X][Y+1] == '#')){
        tiro(X, Y+1);
      }else if((Y-1 > 0) && (mapa[X][Y-1] == '#')){
        tiro(X,Y-1);
      }else if((X+1 <= N+1) && (mapa[X+1][Y] == 'X')){
        tiro(X+1,Y);
      }else if((X-1 > 0)&&( mapa[X-1][Y] == '#')){
        tiro(X-1,Y);
      }
   }
}

int main(){
    cin >> N >> M;
    for(int i=1;i<=N; i++){
        for(int j=1;j<=M;j++){
            char a;
            cin >> a;
            mapa[i][j] = a;
        }
    }
    int k;
    int r = 0;
    cin >> k;
    for(int i=0;i<k;i++){
        int a,b;
        cin >> a >> b;
        if(mapa[a][b] == '#'){
            r++;
            tiro(a,b);
        }
    }
    cout << r;

    return 0;
}
