#include <iostream>

using namespace std;

bool e_primo(unsigned long long int N){
	for (unsigned long long int i = 2; i * i <= N; ++i)
	{
		if(N % i == 0)
			return false;
	}

	return true;
}

int main(int argc, char const *argv[])
{
	unsigned long long int N;
	cin >> N;
	if(e_primo(N)){
		cout << 'N' << endl;
	}else{
		cout << 'S' << endl;
	}
	return 0;
}