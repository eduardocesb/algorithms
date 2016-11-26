#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	map<int, int> notas;
	int r = 0, max = 0;
	for (int i = 0; i < N; ++i)
	{
		int x;
		cin >> x;
		notas[x]++;
		if(max < notas[x]){
			max = notas[x];
			r = x;
		}else if(max == notas[x] && r < x){
			r = x;
		}
	}

	cout << r << endl;
	return 0;
}