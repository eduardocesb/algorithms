#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	int r = 0;
	long double max = 0;
	for (int i = 0; i < N; ++i)
	{
		double D, C;
		cin >> D >> C;
		if(max < C * log10(D)){
			max = C * log10(D);
			r = i;
		}
	}

	cout << r << endl;
	return 0;
}