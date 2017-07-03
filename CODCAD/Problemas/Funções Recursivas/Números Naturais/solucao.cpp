#include <iostream>

using namespace std;

int soma(int N){
	if(N == 1)
		return 1;
	return N + soma(N - 1);
}

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	cout << soma(N) << endl;
	return 0;
}