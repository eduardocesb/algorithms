#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(0); cin.tie(0)

using namespace std;

int Xf, Yf, Xi, Yi, Vi, R1, R2;

double distancia()
{
	return sqrt(pow(Xf - Xi, 2) + pow(Yf - Yi, 2));
}

int main(int argc, char** argv)
{
	optimize;

	while((cin >> Xf >> Yf >> Xi >> Yi >> Vi >> R1 >> R2) && !cin.eof())
		cout << (R1 + R2 >= (distancia() + (1.5 * Vi)) ? 'Y' : 'N') << endl;
	return 0;
}
