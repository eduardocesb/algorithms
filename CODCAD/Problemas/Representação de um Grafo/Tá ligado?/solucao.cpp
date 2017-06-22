#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, M;
	cin >> N >> M;
	map<pair<int, int>, bool>mapa;

	for (int i = 0; i < M; ++i)
	{
		int t, a, b;
		cin >> t >> a >> b;
		if(t == 0){
			cout << mapa[make_pair(a, b)] << endl;
		}else{
			mapa[make_pair(a, b)] = 1;
			mapa[make_pair(b, a)] = 1;
		}
	}
	return 0;
}