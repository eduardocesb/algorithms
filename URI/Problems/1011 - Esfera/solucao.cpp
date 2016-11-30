#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
	double PI = 3.14159;
	double R;
	cin >> R;
	double V = (4/3.0) * PI * (pow(R, 3));
	printf("VOLUME = %.3f\n", V);
	return 0;
}