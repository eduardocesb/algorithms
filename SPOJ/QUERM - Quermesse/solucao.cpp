#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int teste = 1;
	while(n != 0){
		cout << "Teste " << teste << endl;
		for(int i =1;i<=n;i++){
			int e;
			cin >> e;
			if(e == i){
				cout << e << endl;
			}
		}
		cout << endl;
		cin >> n;
		teste++;
	}
	
	return 0;
}
