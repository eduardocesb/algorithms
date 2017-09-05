#include <cstdio>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>

#define NMAX 100000
#define NMIN 2


using namespace std;

vector<int> adj[2][NMAX];
set<pair<int,int> > arestas[2];

vector<int> folhas[2];
vector<int> filhos[2][NMAX];


int tipo[2][NMAX];
vector<int> tiposatuais[2];

int ntipos;
map<string, int> hashtipos;

int grau[2][NMAX];

int n[2];

int fila[NMAX];
int foi[NMAX];

int conexo(int q)
{
	int inicio = 0;
	int fim = 1;
	int atual;
	int i;
	
	for (i=0; i<n[q]; i++)
		foi[i] = 0;
	
	
	foi[0] = 1;
	fila[0] = 0;
	while (1)
	{
		if (inicio == fim)
			break;
		atual = fila[inicio];
		inicio++;
		
		for (i=0; i<(int)adj[q][atual].size(); i++)
			if (!foi[adj[q][atual][i]])
			{
				fila[fim] = adj[q][atual][i];
				fim ++;
				if (fim == n[q])
					return 1;
				foi[adj[q][atual][i]] = 1;
			}
	}
	
	return 0;
}

char str[10*NMAX];


int _hash(vector<int> vetor, int j)
{
	vector <int> temp;
	int i;
	string s;
	int tam = 0;
	char aux[10];
	

	
	for (i=0; i<(int)vetor.size(); i++)
	{
		temp.push_back(tipo[j][vetor[i]]);
	}
	
	sort(temp.begin(), temp.end());
	
	for (i=0; i<(int)temp.size(); i++)
	{
		if (i)
		{
			str[tam] = ' ';
			tam++;
		}
		sprintf(aux, "%d", temp[i]);
		strcpy(&str[tam], aux);
		tam += strlen(aux);
	}
				
	s = str;
	
	if (hashtipos.find(s)==hashtipos.end())
	{
		hashtipos[s] = ntipos;
		ntipos++;
	}
	
	return hashtipos[s];
}

void legrafo(int q, int size)
{
	int i;
	int x, y;

	n[q]=size;
	
	for (i=0; i<n[q]; i++)
	{
		grau[q][i] = 0;
		adj[q][i].clear();
		filhos[q][i].clear();
	}
	arestas[q].clear();
	
	for (i=1; i<n[q]; i++)
	{
		scanf("%d %d", &x, &y);
		
		x--;
		y--;
		
		grau[q][x]++;
		grau[q][y]++;
		adj[q][x].push_back(y);
		adj[q][y].push_back(x);
		arestas[q].insert(make_pair(x,y));
		arestas[q].insert(make_pair(y,x));
	}
	
}

int main()
{	
  int m, total[2],size;
	int i, j, k;
	int isomorfo;
	
	while (1)
	{
	  if (scanf("%d", &size)!=1)
		break;
		
	  legrafo(0,size);
	  legrafo(1,size);
		
		if (n[0] != n[1])
		{
			printf("N\n");
			continue;
		}
		
		total[0] = total[1] = 0;
		isomorfo = 1;
		ntipos = 1;
		
		hashtipos.clear();
		
		while (isomorfo)
		{
			for (j=0; j<2; j++)
			{
				folhas[j].clear();
				for (i=0; i<n[j]; i++)
				{
					if (grau[j][i] == 1) // acha folhas
					{
						folhas[j].push_back(i); //adiciona folhas na lista de folhas
						grau[j][i] = 0;
						total[j]++;
					}
				}
			}
			
			if (folhas[0].size() != folhas[1].size()) //numero de folhas diferentes
			{
				isomorfo = 0;
				break;
			}
			
			for (j=0; j<2; j++)
			{
				tiposatuais[j].clear();
				for (i=0; i<(int)folhas[j].size(); i++)
				{
					// atribui um tipo a cada folha
					if ((int) adj[j][folhas[j][i]].size() == 1)
						tipo[j][folhas[j][i]] = 0;
					else {
						tipo[j][folhas[j][i]] = _hash(filhos[j][folhas[j][i]], j);
					}
					
					//monta a lista de tipos
					tiposatuais[j].push_back(tipo[j][folhas[j][i]]);
					
					if (total[j]!=n[j]) // se eh a ultima iteracao, nao precisa
					{
						//acha o pai de cada folha
						for (k=0; k<(int)adj[j][folhas[j][i]].size(); k++)
							if (grau[j][adj[j][folhas[j][i]][k]] > 0)
								break;
						
						//diminui o grau do pai
						grau[j][adj[j][folhas[j][i]][k]]--;
						if (grau[j][adj[j][folhas[j][i]][k]] == 0) //se era ultimo vertice do grafo
							grau[j][adj[j][folhas[j][i]][k]]++; //incrementa para saber q eh folha
						filhos[j][adj[j][folhas[j][i]][k]].push_back(folhas[j][i]); //adiciona a folha na lista do pai
					}
				}
				
			}
			
			//ordena as listas de tipos das folhas, para poder comparar
			for (j=0; j<2; j++)
				sort(tiposatuais[j].begin(), tiposatuais[j].end());
		
			
			for (i=0; i<(int)tiposatuais[0].size(); i++)
			{
				if (tiposatuais[0][i] != tiposatuais[1][i]) //se as folhas nao sao isomorfas
					isomorfo = 0;
			}
			
			
			if (total[0] == n[0] || total[1] == n[1])
				break;
					
		}
		
		
		if (isomorfo)
		{
			printf("S\n");
		}
		else
		{
			printf("N\n");
		}

	}
	return 0;
}

