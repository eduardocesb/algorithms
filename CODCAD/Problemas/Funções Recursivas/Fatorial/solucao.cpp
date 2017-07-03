#include <iostream>

using namespace std;

int fatorial(int N){
	if(N < 2)
		return 1;
	return N * fatorial(N - 1);
}

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	cout << fatorial(N) << endl;
	return 0;
}