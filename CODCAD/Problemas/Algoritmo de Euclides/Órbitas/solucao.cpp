#include <iostream>

using namespace std;

unsigned long long MDC(unsigned long long a, unsigned long long b){
	if(b == 0)
		return a;
	return MDC(b, a % b);
}

unsigned long long MMC(unsigned long long a, unsigned long long b){
	return (a * b) / MDC(a, b);
}

int main(int argc, char const *argv[])
{
	unsigned long long A, B;
	cin >> A >> B;
	cout << MMC(A, B) << endl;
	return 0;
}