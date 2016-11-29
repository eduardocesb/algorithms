#include <iostream>

using namespace std;

int fatorial(int x){
	int fat[x+1];
	fat[0] = 1;
	fat[1] = 1; 
	for(int i=2;i<=x;i++){
		fat[i] = fat[i-1] *i;
	}
	return fat[x];
}

int main(){
	int n;
	cin >> n;
	cout << fatorial(n) << endl;
}
