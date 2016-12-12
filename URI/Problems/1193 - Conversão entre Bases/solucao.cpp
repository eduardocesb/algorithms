#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

string DecToBin(int n){
	string r = "";
	while(n > 0){
		int x = n%2;
		string res = "";
		res += '0' + x;
		r.insert(0, res);
		n -= x;
		n = n/2;
	}
	return r;
}

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	for (int i = 1; i <= N ; ++i)
	{
		string num, base;
		cin >> num >> base;
		cout << "Case " << i << ":" << endl;
		if(base == "bin"){
			int numero_decimal = stoi(num, nullptr, 2);
			cout << numero_decimal << " dec" << endl;
			printf("%x hex\n\n", numero_decimal);
		}else if(base == "dec"){
			int numero_decimal = stoi(num, nullptr, 0);
			printf("%x hex\n", numero_decimal);
			cout << DecToBin(numero_decimal) << " bin" << endl << endl;
		}else if(base == "hex"){
			int numero_decimal = stoi(num, nullptr, 16);
			cout << numero_decimal << " dec" << endl;
			cout << DecToBin(numero_decimal) << " bin" << endl << endl;
		}
	}
	return 0;
}