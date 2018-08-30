#include <bits/stdc++.h>

using namespace std;

struct Nota
{
	string nome;
	int nota;

	bool operator < (const Nota &a) const
	{
		if(a.nota != nota)
			return nota < a.nota;
		return nome > a.nome;
	}
};

int main(int argc, char** argv)
{
	int N, t = 1;

	Nota r, x;


	while(cin >> N)
	{
		r.nota = 11;
		for(int i = 0; i < N; i++)
		{
			cin >> x.nome >> x.nota;

			r = min(r, x);
		}

		cout << "Instancia " << t++ << endl;
		cout << r.nome << endl << endl;
	}
	return 0;
}
