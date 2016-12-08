#include <iostream>
#include <list>
#include <sstream>

using namespace std;

class Grafo{
private:
	int V;
	list<int> *adj;
public:
	Grafo(int V){
		this->V = V;
		adj = new list<int>[V];
	}

	void addAresta(int v1, int v2){
		adj[v1].push_back(v2);
	}

	int GrauDeSaida(int v){
		return adj[v].size();
	}
	int GrauDeEntrada(int v){
		int r = 0;
		for (int i = 1; i < V; ++i)
		{
			int tam = adj[i].size();
			list<int>::iterator it;
			for (it = adj[i].begin(); it != adj[i].end(); it++)
			{
				if(*it == v){
					r++;
				}
			}
		}
		return r;
	}
};

int main(int argc, char const *argv[])
{
	int A, V;
	cin >> A >> V;
	int teste = 1;
	while(A != 0 || V != 0){
		Grafo g(A+1);
		for (int i = 0; i < V; ++i)
		{
			int x, y;
			cin >> x >> y;
			g.addAresta(x, y);
		}

		int max = -1;
		string r = "";
		stringstream str;
		for(int i = 1; i<= A; i++){
			int total = g.GrauDeSaida(i) + g.GrauDeEntrada(i);
			if(total > max){
				stringstream str;
				str << i;
				r = "";
				r = str.str();
				max = total;
			}else if(max == total){
				stringstream str;
				str << i;
				r += " " + str.str();
			}
		}
		cout << "Teste " << teste << endl;
		cout << r << endl << endl;
		teste++;
		cin >> A >> V;
	}
	return 0;
}