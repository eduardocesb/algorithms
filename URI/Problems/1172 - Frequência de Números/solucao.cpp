#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	map<int, int> nums;
	map<int, int> indice;
	for (int i = 0; i < N; ++i)
	{
		int x;
		cin >> x;
		nums[x]++;
		indice[x] = x;
	}

	map<int, int>::iterator it;
	for(it = indice.begin(); it != indice.end(); it++){
		cout << it->first << " aparece " << nums[it->first] << " vez(es)" << endl;
	}
	return 0;
}