#include <iostream>
#include <cmath>

using namespace std;

bool eh_primo(int x){
	//O 1 não é primo...
	if(x == 1){
		return false;
	}
	//Só preciso ir até a raiz quadrada do número...
	int max = sqrt(x);
	for (int i = 2; i <= max; ++i)
	{
		//Se dividir não é primo...
		if(x % i == 0){
			return false;
		}
	}
	//Se chegou até aqui é porque é primo...
	return true;
}

int main(int argc, char const *argv[])
{
	int x;

	cin>>x;

	if(eh_primo(x)){
		cout<<"S"<<"\n";
	}else{
		cout<<"N"<<"\n";
	}
}
