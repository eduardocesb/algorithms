#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string x;
		cin >> x;
		int tam = x.size();
		int pilha = 0;
		int r = 0;
		for (int j = 0; j < tam; ++j)
		{
			if(x[j] == '<'){
				pilha++;
				continue;
			}
			if(x[j] == '>'){
				if(pilha > 0){
					pilha--;
					r++;
				}
				continue;
			}
		}
		cout << r << endl;
	}
	return 0;
}