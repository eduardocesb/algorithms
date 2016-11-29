#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
	string a,b;
	while(!(cin >> a >> b).eof()){
		if(a.find(b) != string::npos){
			cout << "Resistente" << endl;
		}else{
			cout << "Nao resistente" << endl;
		}
	}
	return 0;
}