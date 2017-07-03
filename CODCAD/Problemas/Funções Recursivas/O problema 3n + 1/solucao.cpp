#include <iostream>

using namespace std;

unsigned long long f(int N){
	if(N == 1)
		return 0;
	if(N % 2 == 0)
		return 1 + f(N/2);
	return 1 + f((3*N) + 1);
}

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	cout << f(N) << endl;
	return 0;
}