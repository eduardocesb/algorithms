#include <iostream>

using namespace std;

unsigned long long int MDC(unsigned long long int a, unsigned long long int b){
	if(b == 0)
		return a;
	return MDC(b, a % b);
}

int main(int argc, char const *argv[])
{
	unsigned long long int N, M;
	cin >> N >> M;
	for (unsigned long long int i = M; i > 0 ; i--)
	{
		if(MDC(N, i) == 1){
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}