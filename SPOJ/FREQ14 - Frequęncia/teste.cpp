#include <iostream>
using namespace std;

int main(){
    int N, Q;
    cin >> N >> Q;
    int Mat[N][N];
    for(int i=0;i<Q;i++){
        int a;
        cin >> a;
        if(a == 1){
            int x,r;
            cin >> x >> r;
            for(int j=0;j<N;j++){
                mat[x][j] = r;
            }
        }else if(a == 2){
            int x,r;
            cin >> x >> r;
            for(int j=0;i<N;j++){
                mat[j][x] = r;
            }
        }else if(a == 3){
            int x;
            cin >> x;

        }
    }
    return 0;
}
