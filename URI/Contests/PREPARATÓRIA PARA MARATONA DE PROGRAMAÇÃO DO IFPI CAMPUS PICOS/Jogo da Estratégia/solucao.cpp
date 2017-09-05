#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int r, maior = -1;
	int J, R, x, da_vez = 1;
	cin >> J >> R;
	int pontos[J + 1];

	memset(pontos, false, 	sizeof(pontos));

	for (int i = 1; i <= (J * R); ++i)
	{
		cin >> x;
		if(da_vez > J) da_vez = 1;
		pontos[da_vez] += x;
		if(pontos[da_vez] >= maior){
			maior = pontos[da_vez];
			r = da_vez;
		}

		da_vez++;
	}

	cout << r << endl;
	return 0;
}