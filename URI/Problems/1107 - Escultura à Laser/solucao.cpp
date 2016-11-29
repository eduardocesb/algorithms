#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, M;
	cin >> N >> M;
	while(N != 0 || M != 0){
		int anterior = N;
		int r = 0;
		for (int i = 0; i < M; ++i)
		{
			int atual;
			cin >> atual;
			if(anterior > atual){
				r += anterior - atual;
			}

			anterior = atual;
		}
		cout << r << endl;
		cin >> N >> M;
	}
	return 0;
}