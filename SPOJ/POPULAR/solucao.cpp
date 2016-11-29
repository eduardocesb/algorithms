#include <iostream>

using namespace std;

int n;

int matrix[100][100];

int coluna[100];

void soma_coluna(int i){

    for(int cont=0;cont<100;cont++){
        coluna[i] += matrix[cont][i];
    }
}


int main(){
    cin >> n;
    while(n!=0){

        for(int i=0;i<100;i++){
            coluna[i] = 0;
            for(int j=0;j<100;j++){
                matrix[i][j] = 0;
            }
        }

        int r=0;
        for(int i=0;i<n;i++){
            coluna[i] = 0;
            for(int j=0;j<n;j++){
                int e;
                cin >> e;
                matrix[i][j] = e;
            }
        }
        for(int i=0;i<100;i++){
            soma_coluna(i);
            if(r < coluna[i]){
                r = coluna[i];
            }
        }
        cout << r << endl;
        cin >> n;
    }
    return 0;
}
