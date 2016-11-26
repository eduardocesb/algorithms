#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	map<int, bool> fila;
	vector<int> nums;
	for (int i = 0; i < N; ++i)
	{
		int x;
		cin >> x;
		fila[x] = true;
		nums.push_back(x);
	}
	int M;
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int x;
		cin >> x;
		fila[x] = false;
	}

	int tam = nums.size();
	for (int i = 0; i < tam; ++i)
	{
		if(fila[nums[i]])
			cout << nums[i] << " ";
	}
	cout << endl;
	return 0;
}