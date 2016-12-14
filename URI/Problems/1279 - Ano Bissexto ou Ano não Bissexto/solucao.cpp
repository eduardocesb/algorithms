#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int toInt(const string& num) {
   istringstream stream(num);
   int result;
   stream >> result;
   return result;
}

bool AnoBissexto(const string& year){
	int lastTwo = toInt(year.substr(year.size() - 2));
   	bool divisibleBy4 = lastTwo % 4 == 0,
        divisibleBy100 = lastTwo == 0,
        divisibleBy400 = toInt(year.substr(year.size() - 4, 2)) % 4 == 0
           && lastTwo == 0;
   return divisibleBy4 && (!divisibleBy100 || divisibleBy400);
}

bool DivisivelPor3(string ano, int tam){
	long long int soma = 0;
	for (int i = 0; i < tam; ++i)
	{
		soma += (ano[i] - '0');
	}
	return (soma % 3 == 0);
}

bool DivisivelPor5(string ano, int tam){
	bool x;
	if(ano[tam-1] =='5' || ano[tam-1] == '0'){
		x = true;
	}else{
		x = false;
	}
	return x;
}

bool DivisivelPor11(string ano, int tam){
	long long int somaI = 0;
	for (int i = tam-1; i >= 0; i -= 2)
	{
		somaI += (ano[i] - '0');
	}
	long long int somaP = 0;
	for (int i = tam-2; i >= 0; i -= 2)
	{
		somaP += (ano[i] - '0');
	}
	long r = (somaI - somaP);
	if(r < 0)
	{
		r *= -1;
	}
	return (r%11==0);
}

int main(int argc, char const *argv[])
{
	string ano;
	int cont = 0;
	while(!(cin >> ano).eof()){
		if(cont != 0){
			cout << endl;
		}
		int tam = ano.size();
		bool bissexto = false, huluculu = false, bulukulu = false;
		if(AnoBissexto(ano)){
			bissexto = true;
		}
		if(DivisivelPor3(ano, tam) && DivisivelPor5(ano, tam)){
			huluculu = true;
		}
		if(bissexto == true && (DivisivelPor5(ano, tam) && (DivisivelPor11(ano, tam)))){
			bulukulu = true;
		}
		if(bissexto || huluculu || bulukulu){
			if(bissexto){
				cout << "This is leap year." << endl;
			}
			if(huluculu){
				cout << "This is huluculu festival year." << endl;
			}
			if(bulukulu){
				cout << "This is bulukulu festival year." << endl;
			}
		}else{
			cout << "This is an ordinary year." << endl;
		}
		cont = 1;
	}
	return 0;
}