#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, x, atual = 0, max = 0;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> x;
		atual += x;
		if(max < atual)
			max = atual;

		if(atual < 0)
			atual = 0;
	}
	cout << max << endl;
	return 0;
}