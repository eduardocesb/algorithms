#include <iostream>

using namespace std;

int chamadas = -1;

int fib(int n){
	chamadas++;
	if(n < 2){
		return n;
	}
	return fib(n-1) + fib(n-2);
}

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		chamadas = -1;
		int x;
		cin >> x;
		int qtd = fib(x);
		cout << "fib(" << x << ") = " << chamadas << " calls = " << qtd << endl;
	}
	return 0;
}