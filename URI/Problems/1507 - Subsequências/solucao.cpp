#include <iostream>

using namespace std;

bool tem_substring(string palavra, string p){
	int tam1 = palavra.size();
	int tam2 = p.size();

	int i = 0, j = 0;
	while(i < tam1 && j < tam2){
		if(palavra[i] == p[j]){
			j++;
		}
		i++;
	}
	return j == tam2;
}

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string palavra;
		cin >> palavra;
		int x;
		cin >> x;
		for (int i = 0; i < x; ++i)
		{
			string p;
			cin >> p;
			if(tem_substring(palavra, p)){
				cout << "Yes" << endl;
			}else{
				cout << "No" << endl;
			}
		}
	}
	return 0;
}