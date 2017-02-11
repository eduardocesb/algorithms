#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int lis(vector<char> &v){
	vector<char> pilha;
	int tam = v.size();
	for (int i = 0; i < tam; ++i)
	{
		vector<char>::iterator it = upper_bound(pilha.begin(), pilha.end(), v[i]);
		if(it == pilha.end()){
			pilha.push_back(v[i]);
		}else{
			*it = v[i];
		}
	}
	return pilha.size();
}

int main(int argc, char const *argv[])
{
	vector<char> letras;
	char c;
	while(scanf("%c", &c) and c != '\n'){
		letras.push_back(c);
	}

	int r = lis(letras);
	printf("%d\n", r);
	return 0;
}