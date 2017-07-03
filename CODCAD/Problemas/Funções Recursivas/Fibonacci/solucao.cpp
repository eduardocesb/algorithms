#include <iostream>

using namespace std;

unsigned long long fib(int N){
	if(N < 2)
		return 1;
	return fib(N - 1) + fib(N - 2);
}

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	cout << fib(N) << endl;
	return 0;
}