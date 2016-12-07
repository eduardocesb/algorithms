#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	unsigned long long patos;
	cin >> patos;
	while(patos != -1){
		if(patos < 2){
			cout << "0" << endl;
		}else{
			cout << patos-1 << endl;
		}
		cin >> patos;
	}
	return 0;
}