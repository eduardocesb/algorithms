#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{
	double a, b;
	cin >> a >> b;
	cout << fixed << setprecision(2) << a/b << endl;
	return 0;
}