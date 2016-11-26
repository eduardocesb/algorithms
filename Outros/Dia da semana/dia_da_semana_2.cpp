#include <iostream>
#include <string>

using namespace std;

int dia, mes, ano;
int ano_inicial = 1995;
int dia_inicial = 1;
int mes_inicial = 1;
pair<string, int> meses[] = {	make_pair("Janeiro", 31), 
															make_pair("Fevereiro", 28),
															make_pair("Março", 31),
															make_pair("Abril", 30),
															make_pair("Maio", 31),
															make_pair("Junho", 30),
															make_pair("Julho", 31),
															make_pair("Agosto", 31),
															make_pair("Setembro", 30),
															make_pair("Outubro", 31),
															make_pair("Novembro", 30),
															make_pair("Dezembro", 31)};
														
bool ano_bisexto(int ano){
	if(ano % 4 == 0 && (ano % 400 == 0 || ano % 100 != 0)){
		return true;
	}else{
		return false;
	}
}
	
int dias_do_mes(int mes, int ano){
	if(mes == 2 && (ano_bisexto(ano))){
		return 29;
	}else{
		return meses[mes-1].second;
	}
}
int dias_do_ano(int ano){
	if(ano_bisexto(ano)){
		return 366;
	}else{
		return 365;
	}
}

int quantidade_dias(int dia_atual, int mes_atual, int ano_atual){
	int a = 0;
	int m = 0;
	int d = 0;
	//Calcula a quantidade de dias entre o intervalo de anos...
	for(int i = ano_atual+1; i < ano_inicial; i++){
		a += dias_do_ano(i);
	}
	//Calcula a quantidade de dias entre o intervalo de meses...
	for(int i = mes_atual+1; i <= 12; i++){
		m += dias_do_mes(i, ano_atual);
	}
	d = 31 - dia_atual;
	return a + m + d;
}

string dia_da_semana(int i){
	switch(i){
	case 6:
		return "Domingo";
		break;
	case 5:
		return "Segunda";
		break;
	case 4:
		return "Terça";
		break;
	case 3:
		return "Quarta";
		break;
	case 2:
		return "Quinta";
		break;
	case 1:
		return "Sexta";
		break;
	case 0:
		return "Sábado";
		break;
	}
}
int r;

int main(){
	cin >> dia >> mes >> ano;
	r = quantidade_dias(dia, mes, ano);
	r = r % 7;
	cout << r << " " << dia_da_semana(r) << endl;
	int tam_meses = meses[mes-1].second;
	cout << "\n---------------------\n";
	cout <<    "D  S  T  Q  Q  S  S";
	cout << "\n---------------------\n";
	int c = 1;
	for(int k=-(5-r); k <= tam_meses; k++){
//		cout << " K " << k << endl;
		if(k<1){
			cout << "   ";
		}else{
			if(c%7==1){
				cout << endl;
			}		
			if(k < 10){
				cout << "0" << k << " ";
			}else{
				cout << k << " ";
			}
		}
		c++;
	}
	return 0;
}
