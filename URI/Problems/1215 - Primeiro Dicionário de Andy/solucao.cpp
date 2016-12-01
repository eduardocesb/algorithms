#include <iostream>
#include <map>
#include <ctype.h>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	string x;
	map<string, string> palavras;
	while(!(cin >> x).eof()){
		transform(x.begin(), x.end(), x.begin(), ::tolower);
		int tam = x.size();
		string p = "";
		for (int i = 0; i < tam; ++i)
		{
			if(isalpha(x[i])){
				p += x[i];
			}else{
				if(!p.empty()){
					palavras[p] = p;
				}
				p = "";
			}
		}
		if(!p.empty()){
			palavras[p] = p;
		}
	}
	map<string, string>::iterator it;
	for(it = palavras.begin(); it != palavras.end(); it++)
	{
		cout << it->first << endl;
	}
	return 0;
}