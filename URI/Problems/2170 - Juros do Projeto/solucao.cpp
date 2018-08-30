#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
	double x, y;

	int t = 1;
	cout << setprecision(2) << fixed;

	while(cin >> x >> y)
	{
		cout << "Projeto " << t++ << ":" << endl;
		cout << "Percentual dos juros da aplicacao: " << ((y * 100.0 / x) - 100) << " %" << endl << endl;
	}
	
	return 0;
}
