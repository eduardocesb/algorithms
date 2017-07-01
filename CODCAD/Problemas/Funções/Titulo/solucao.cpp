#include <iostream>
#include <string>
#include <locale>

using namespace std;

string title(string F){
	char ant;
	int tam = F.length();
	string s = "";
	locale loc;
	for (int i = 0; i < tam; ++i)
	{
		if(i == 0 || ant == ' '){
			s += toupper(F[i], loc);
		}else{
			s += tolower(F[i], loc);
		}

		ant = F[i];
	}

	return s;
}

int main(){ 
	string F;

	getline(cin, F);

	cout<<title(F)<<"\n";
}

