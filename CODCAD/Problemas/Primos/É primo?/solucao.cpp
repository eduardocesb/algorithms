#include <iostream>

using namespace std;

bool e_primo(unsigned long long int N){
	if(N == 1)
		return false;
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
		cout << 'S' << endl;
	}else{
		cout << 'N' << endl;
	}
	return 0;
}