#include <iostream>

using namespace std;

bool e_divisivel_por_2(string num){
	int n = num[num.length() - 1] - '0';
	return n%2 == 0;
}

bool e_divisivel_por_3(string num){
	int soma = 0;
	int tam = num.length();
	for (int i = 0; i < tam; ++i)
	{
		soma += num[i] - '0';
	}
	return soma%3 == 0;
}

bool e_divisivel_por_5(string num){
	return num[num.length() - 1] == '0' || num[num.length() - 1] == '5';
}

int main(int argc, char const *argv[])
{
	string num;
	cin >> num;
	if(e_divisivel_por_2(num))
		cout << 'S' << endl;
	else
		cout << 'N' << endl;
	if(e_divisivel_por_3(num))
		cout << 'S' << endl;
	else
		cout << 'N' << endl;
	if(e_divisivel_por_5(num))
		cout << 'S' << endl;
	else
		cout << 'N' << endl;
	return 0;
}