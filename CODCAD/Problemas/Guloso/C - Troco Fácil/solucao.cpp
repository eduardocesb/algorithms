#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int n, r = 0;
	cin >> n;
	//Quantidade de notas de 100...
	r += n/100;
	n %= 100;
	//Quantidade de notas de 50...
	r += n/50;
	n %= 50;
	//Quantidade de notas de 25...
	r += n/25;
	n %= 25;
	//Quantidade de notas de 10..
	r += n/10;
	n %= 10;
	//Quantidade de notas de 5...
	r += n/5;
	n %= 5;
	//Quantidade de notas de 1...
	r += n;
	//Imprimo o valor...
	cout << r << endl;
	return 0;
}