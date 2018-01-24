#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(0); cin.tie(0)

using namespace std;

int main(int argc, char const *argv[])
{
	optimize;

	int N, r, m;
	double nota_max = -1, nota;

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> m >> nota;

		if(nota > nota_max)
		{
			nota_max = nota;
			r = m;
		}
	}

	if(nota_max < 8)
		cout << "Minimum note not reached" << endl;
	else
		cout << r << endl;

	return 0;
}