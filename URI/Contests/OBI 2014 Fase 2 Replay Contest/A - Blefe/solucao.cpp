#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, bool> numsA;
unordered_map<int, bool> numsB;

bool blefe(int x){
	if(numsA[x] == true){
		return false;
	}else{
		numsA.erase(x);
	}

	unordered_map<int, bool>::iterator it;
	for(it = numsB.begin(); it != numsB.end(); it++){
		int da_vez = it->first;
		int diferenca = x - da_vez;
		if(numsB[diferenca] == true){
			return false;
		}else{
			numsB.erase(diferenca);
		}
	}

	return true;
}

int main(int argc, char const *argv[])
{
	int A, B;
	cin >> A >> B;
	for (int i = 0; i < A; ++i)
	{
		int x;
		cin >> x;
		numsA[x] = true;
	}

	int r = 0;
	bool deu_certo = true;

	for (int i = 0; i < B; ++i)
	{
		int x;
		cin >> x;
		if(deu_certo && blefe(x)){
			deu_certo = false;
			r = x;
		}
		numsB[x] = true;
	}

	if(deu_certo){
		cout << "sim" << endl;
	}else{
		cout << r << endl;
	}

	return 0;
}