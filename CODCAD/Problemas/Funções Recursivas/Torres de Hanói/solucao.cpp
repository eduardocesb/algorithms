#include <iostream>

using namespace std;

unsigned long long hanoi(int N){
	if(N == 1)
		return 1;
	return 1 + (2 * hanoi(N - 1));
}

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	int teste = 1;
	while(N != 0){
		cout << "Teste " << teste << endl;
		teste++;
		cout << hanoi(N) << endl << endl;
		cin >> N;
	}
	return 0;
}