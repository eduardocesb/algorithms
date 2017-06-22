#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int periodo1[n][n];
	int periodo2[n][n];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> periodo1[i][j];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> periodo2[i][j];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << periodo1[i][j] + periodo2[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}