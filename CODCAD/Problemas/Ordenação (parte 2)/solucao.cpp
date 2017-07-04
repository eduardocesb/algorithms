#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Pais{
private:
	int id, ouro, prata, bronze;
public:

	Pais(int id, int o, int p, int b){
		this->id = id;
		ouro = o;
		prata = p;
		bronze = b;
	}

	int ID(){
		return id;
	}

	bool operator <(const Pais& a)const{
		if(ouro == a.ouro && prata == a.prata && bronze == a.bronze)
			return id < a.id;
		if(ouro == a.ouro && prata == a.prata)
			return bronze > a.bronze;
		if(ouro == a.ouro)
			return prata > a.prata;
		return ouro > a.ouro;
	}
};

int main(int argc, char const *argv[])
{
	int N, M;
	cin >> N >> M;
	vector<Pais> paises;
	int medalhas[N][3];
	for (int i = 0; i < N; ++i)
	{
		medalhas[i][0] = medalhas[i][1] = medalhas[i][2] = 0;
	}

	for (int i = 0; i < M; ++i)
	{
		int o, p ,b;
		cin >> o >> p >> b;
		medalhas[o - 1][0]++;
		medalhas[p - 1][1]++;
		medalhas[b - 1][2]++;
	}

	for (int i = 0; i < N; ++i)
	{
		paises.push_back(Pais(i+1, medalhas[i][0], medalhas[i][1], medalhas[i][2]));
	}

	sort(paises.begin(), paises.end());

	for (int i = 0; i < N; ++i)
	{
		cout << paises[i].ID() << ' ';
	}

	cout << endl;
	return 0;
}