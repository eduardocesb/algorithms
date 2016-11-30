#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	int anos = N/365;
	N = N%365;
	int meses = N/30;
	N = N%30;
	int dias = N;
	cout << anos << " ano(s)" << endl;
	cout << meses << " mes(es)" << endl;
	cout << dias << " dia(s)" << endl;
	return 0;
}