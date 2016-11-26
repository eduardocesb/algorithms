#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, M;
	cin >> N >> M;
	int ultimo = -1;
	bool achou = false, deu_certo = true;
	for (int i = 0; i < N; ++i)
	{
		achou = false;
		for (int j = 0; j < M; ++j)
		{
			int x;
			cin >> x;
			if(deu_certo && !achou && x){
				if(j > ultimo){
					ultimo = j;
				}else{
					deu_certo = false;
				}
				achou = true;
			}else if(deu_certo && !achou && !x && j == M-1){
				ultimo = M;
			}
		}
	}
	if(deu_certo){
		cout << "S" << endl;
	}else{
		cout << "N" << endl;
	}
	return 0;
}