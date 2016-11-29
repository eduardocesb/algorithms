#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Placar{
	string time1, time2;
	int gols1, gols2;
public:
	Placar(string t1, int g1, string t2, int g2){
		time1 = t1;
		time2 = t2;
		gols1 = g1;
		gols2 = g2;
	}

	string ObterTime1(){
		return time1;
	}

	string ObterTime2(){
		return time2;
	}

	int ObterGols1(){
		return gols1;
	}

	int ObterGols2(){
		return gols2;
	}

	bool empate(){
		if(gols1 == gols2){
			return true;
		}
		return false;
	}

	bool Time1_Ganhou(){
		if(gols1 > gols2){
			return true;
		}
		return false;
	}

	bool Time2_Ganhou(){
		if(gols2 > gols1){
			return true;
		}
		return false;
	}

};


bool empate(Placar p, Placar x){
	if(p.ObterGols1() == p.ObterGols2() && x.ObterGols1() == x.ObterGols2()){
		return true;
	}
	return false;
}

bool acertou_placar(Placar p, Placar x){
	int sp = p.ObterGols1() - p.ObterGols2();
	int sx = x.ObterGols1() - x.ObterGols2();
	if(p.empate() && x.empate()){
		return true;
		//cout << "1" << endl;
	}
	if(x.Time1_Ganhou() && p.Time1_Ganhou()){
		//cout << "2" << endl;
		return true;
	}

	if(x.Time2_Ganhou() && p.Time2_Ganhou()){
		//cout << "3" << endl;
		return true;
	}
	return false;
}


bool acertou_gols_marcados_por_o_time1(Placar p, Placar x){
	if(p.ObterGols1() == x.ObterGols1()){
		return true;
	}
	return false;
}
bool acertou_gols_marcados_por_o_time2(Placar p, Placar x){
	if(p.ObterGols2() == x.ObterGols2()){
		return true;
	}
	return false;
}

int calcula_pontos(Placar p, Placar x){
	if(acertou_placar(p, x) && acertou_gols_marcados_por_o_time1(p, x) && acertou_gols_marcados_por_o_time2(p, x)){
		//cout << "10 ";
		return 10;
	}

	if(acertou_placar(p, x) && (acertou_gols_marcados_por_o_time1(p ,x) || acertou_gols_marcados_por_o_time2(p ,x))) {
		//cout << "7 ";
		return 7;
	}

	if(acertou_placar(p, x)){
		//cout << "5 ";
		return 5;
	}

	if(acertou_gols_marcados_por_o_time1(p ,x) || acertou_gols_marcados_por_o_time2(p ,x)){
		//cout << "2 ";
		return 2;
	}

	return 0;
}

bool troca(int p1, int p2, string n1, string n2){
	if(p1 > p2){
		return true;
	}

	if(p1 == p2){
		int tam_1 = n1.size();
		for (int i = 0; i < tam_1; ++i)
		{
			if(n1[i] != n2[i]){
				return n1[i] < n2[i];
			}
		}
	}
	return false;
}


int main(int argc, char const *argv[])
{
	int P, N;
	cin >> P >> N;
	while(P != 0 || N != 0){
		unordered_map<string, vector<Placar> > palpites;
		vector<string> jogadores;
		for (int i = 0; i < P; ++i)
		{
			string nome_jogador;
			cin >> nome_jogador;
			jogadores.push_back(nome_jogador);
			vector<Placar> palpite;
			for (int i = 0; i < N; ++i)
			{
				string t1, t2;
				int g1, g2;
				cin >> t1 >> g1 >> t2 >> g2;
				Placar p(t1, g1, t2, g2);
				palpite.push_back(p);
			}
			palpites[nome_jogador] = palpite;
		}

		unordered_map<string, int> pontos;

		for (int i = 0; i < N; ++i)
		{
			string t1, t2;
			int g1, g2;
			cin >> t1 >> g1 >> t2 >> g2;
			Placar p(t1, g1, t2, g2);
			unordered_map<string, vector<Placar> >::iterator it;
			//cout << "Calulando pontos do jogo " << t1 << " vs " << t2 << endl;
			for (it = palpites.begin(); it != palpites.end(); it++)
			{
				string nome_jogador = it->first;
				Placar palpite_da_vez = it->second[i];
				//cout << "Calculando Pontos de " << nome_jogador << endl;
				int pontos_da_vez = calcula_pontos(p, palpite_da_vez);
				//cout << endl;
				pontos[nome_jogador] += pontos_da_vez;
			}
			//cout << endl;
		}

		for (int i = P-1; i >= 0; --i)
		{
			for (int j = 0; j < i ; ++j)
			{
				if(troca(pontos[jogadores[i]], pontos[jogadores[j]] , jogadores[i], jogadores[j])){
					string aux = jogadores[i];
					jogadores[i] = jogadores[j];
					jogadores[j] = aux;
				}
			}
		}

		for(int i = 0; i < P; i++){
			cout << jogadores[i] << " " << pontos[jogadores[i]] << endl;
		}
		cin >> P >> N;
	}


	return 0;
}