#include <iostream>

using namespace std;

unsigned long long mdc(unsigned long long a, unsigned long long b){
	if(b == 0)
		return a;
	return mdc(b, a % b);
}

unsigned long long mmc(unsigned long long a, unsigned long long b){
	return (a * b) / mdc(a, b);
}

int main(int argc, char const *argv[])
{
	unsigned long long A, B, C, D;
	cin >> A >> B >> C >> D;

	unsigned long long baixo = mmc(B, D);
	unsigned long long cima = ((baixo / B) * A) + ((baixo / D) * C);
	unsigned long long mdc_BAIXO_CIMA = mdc(baixo, cima);
	cout << cima / mdc_BAIXO_CIMA << ' ' << baixo / mdc_BAIXO_CIMA << endl;
	return 0;
}