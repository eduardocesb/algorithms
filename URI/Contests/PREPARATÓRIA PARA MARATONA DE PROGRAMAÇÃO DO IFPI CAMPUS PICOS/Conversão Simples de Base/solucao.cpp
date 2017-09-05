#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main ()
{
	string n;
	cin >> n;
	while(n[0] != '-'){
		if(n[1] == 'x'){
			cout << stoi(n,nullptr,16) << endl;
		}else{
			int x =  stoi(n);
			printf("0x%X\n", x);
		}
		cin >> n;
	}

  return 0;
}