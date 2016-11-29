#include <iostream>

using namespace std;

bool fugiu = false;

int main(){
    int N;
    long long M;
    cin >> N >> M;
    M *= M;
    long X=0;
    long Y=0;
    for(int i=0;i<N;i++){
        char direcao;
        int dist=0;
        cin >> direcao >> dist;
        switch(direcao){
            case 'N': Y += dist; break;
            case 'S': Y -= dist; break;
            case 'L': X += dist; break;
            case 'O': X -= dist; break;
        }
        if(X*X + Y*Y > M){
            fugiu = true;
        }
    }
    if(fugiu == true){
        cout << 1;
    }else{
        cout << 0;
    }

    return 0;
}
