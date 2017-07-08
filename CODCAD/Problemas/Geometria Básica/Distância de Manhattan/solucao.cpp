#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int Xm, Ym, Xr, Yr;
	cin >> Xm >> Ym >> Xr >> Yr;

	cout << max(Xr - Xm, Xm - Xr) + max(Yr - Ym, Ym - Yr) << endl;
	return 0;
}