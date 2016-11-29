#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	map<int,bool> visitados;
	int qtd = N;
	for (int i = 0; i < N; ++i)
	{
		int x;
		cin >> x;
		if(visitados[x] == true){
			qtd--;
		}else{
			visitados[x] = true;
		}
	}
	cout << qtd << endl;
	return 0;
}