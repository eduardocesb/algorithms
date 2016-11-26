#include <iostream>

using namespace std;

int main(){
	int N;
	cin >> N;
	while(N!=0){
		int r=0;
		int cont = 0;
		int lado1 = 0;
		bool achou = false;
		for(int i=0; i<N; i++){
			int poste;
			cin >> poste;
			if(poste == 0){
				if(!achou){
					lado1++;
				}
				cont++;
			}else{
				achou = true;
				r += cont/2;
				cont = 0;
			}
		}
		r -= lado1/2;
		r += (cont+lado1)/2;
		cout << r << endl;
		cin >> N;
	}
	return 0;
}
