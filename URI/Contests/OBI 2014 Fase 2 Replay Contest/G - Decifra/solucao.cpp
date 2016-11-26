#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	string alfabeto;
	string frase;
	cin >> alfabeto >> frase;
	int tam = frase.length();
	for (int i = 0; i < tam; ++i)
	{
		int x;
		x = alfabeto.find(frase[i]);
		char l = 'a' + x;
		cout << l;
	}
	cout << endl;
	return 0;
}