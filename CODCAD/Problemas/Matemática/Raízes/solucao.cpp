#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	double x;
	for (int i = 0; i < N; ++i)
	{
		cin >> x;
		cout << fixed << setprecision(4) << sqrt(x) << endl;
	}
	return 0;
}