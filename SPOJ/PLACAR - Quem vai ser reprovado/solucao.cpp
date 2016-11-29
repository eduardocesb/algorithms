#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct aluno{
	char nome[21];
	int nota;

};

bool compara(aluno a1, aluno a2) {
	if(a1.nota != a2.nota){
		return a1.nota < a2.nota;
	}else{
		for(int x=0; x < 21 ; x++){
			if(a1.nome[x] == a2.nome[x]){
				continue;
			}else{
				return a1.nome[x] > a2.nome[x];
			}
		}
	}

}

int main(){
	int n;
	int instancia = 1;
	
	while(scanf("%d", &n) != EOF){
		vector<aluno> alunos(n);
		
		for(int i=0;i<n;i++){
			cin >> alunos[i].nome >> alunos[i].nota;
		}
		sort(alunos.begin(), alunos.end(), compara);
		cout << "Instancia " << instancia << endl;
		cout << alunos[0].nome << endl << endl;
		
		instancia++;
	}
	
	return 0;
	
}
