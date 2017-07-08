#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	long r = 0;
	int X1, Y1, X2, Y2;
	for (int i = 0; i < N; ++i)
	{
		cin >> X1 >> Y1 >> X2 >> Y2;
		r += (max(X1 - X2, X2 - X1) * max(X1 - X2, X2 - X1)) + (max(Y1 - Y2, Y2 - Y1) * max(Y1 - Y2, Y2 - Y1));
	}
	cout << r << endl;
	return 0;
}