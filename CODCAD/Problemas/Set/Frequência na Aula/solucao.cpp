#include <iostream>
#include <set>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, x;
	cin >> N;
	set<int> lista;
	for (int i = 0; i < N; ++i)
	{
		cin >> x;
		lista.insert(x);
	}

	cout << lista.size() << endl;
	return 0;
}