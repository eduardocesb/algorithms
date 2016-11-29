#include <iostream>
#include <algorithm>


using namespace std;

struct aluno{
	char nome[21];
	
};

bool troca(aluno a1, aluno a2){
	for(int x=0;x<21;x++){
		if(a1.nome[x] != a2.nome[x]){
			return a1.nome[x] > a2.nome[x];
		}
	}

}

void resultado(aluno a[], int n, int r){
	
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<i;j++){
			if(troca(a[i], a[j])){
				aluno aux = a[i];
				a[i] = a[j];
				a[j] = aux;
			}
		}
	}
	cout << a[r].nome << endl;
}

int main(){
	int n,r;
	cin >> n >> r;
	aluno alunos[n];
	for(int i=0;i<n;i++){
		cin >> alunos[i].nome;	
	}
	
	resultado(alunos, n, r);

	return 0;
}

