#include <iostream>

using namespace std;

bool e_divisivel_por_4(string num){
	int ultimo = num[num.length() - 1] - '0';
	int penultimo;
	if(num.length() == 1)
		penultimo = 0;
	else
		penultimo = num[num.length() - 2] - '0';
	return (penultimo == 0 && ultimo == 0) || (((penultimo*10) + ultimo)% 4 == 0);
}

bool e_divisivel_por_9(string num){
	int soma = 0;
	int tam = num.length();
	for (int i = 0; i < tam; ++i)
	{
		soma += num[i] - '0';
	}

	return soma % 9 == 0;
}

bool e_divisivel_por_25(string num){
	int ultimo = num[num.length() - 1] - '0';
	int penultimo;
	if(num.length() == 1)
		penultimo = 0;
	else
		penultimo = num[num.length() - 2] - '0';
	return ((penultimo*10) + ultimo) % 25 == 0;
}
int main(int argc, char const *argv[])
{
	string num;
	cin >> num;
	if(e_divisivel_por_4(num))
		cout << 'S' << endl;
	else
		cout << 'N' << endl;
	if(e_divisivel_por_9(num))
		cout << 'S' << endl;
	else
		cout << 'N' << endl;
	if(e_divisivel_por_25(num))
		cout << 'S' << endl;
	else
		cout << 'N' << endl;
	return 0;
}