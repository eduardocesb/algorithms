#include <iostream>

using namespace std;

bool e_divisivel_por_11(string num){
	int Si = 0, Sp = 0;
	int tam = num.length();
	for (int i = tam - 1; i > -1 ; i--)
	{
		if(i % 2 == 0)
			Si += num[i] - '0';
		else
			Sp += num[i] - '0';
	}
	return (Si - Sp) % 11 == 0;
}

int main(int argc, char const *argv[])
{
	string num;
	cin >> num;
	if(e_divisivel_por_11(num))
		cout << 'S' << endl;
	else
		cout << 'N' << endl;
	return 0;
}