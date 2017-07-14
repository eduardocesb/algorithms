#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int N_A, N_B, x;
	cin >> N_A >> N_B;
	set<int> A, B;
	for (int i = 0; i < N_A; ++i)
	{
		cin >> x;
		A.insert(x);
	}

	for (int i = 0; i < N_B; ++i)
	{
		cin >> x;
		B.insert(x);
	}

	int tam_b = 0;
	int tam_a = 0;

	for (set<int>::iterator it = A.begin(); it != A.end(); it++)
	{
		if(B.find(*it) == B.end())
			tam_a++;
	}

	for (set<int>::iterator it = B.begin(); it != B.end(); it++)
	{
		if(A.find(*it) == A.end())
			tam_b++;
	}
	cout << min(tam_a, tam_b) << endl;
	return 0;
}