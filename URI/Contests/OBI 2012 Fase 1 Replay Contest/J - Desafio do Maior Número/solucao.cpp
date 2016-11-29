#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int N;
	int R = 0;
	do{
		cin >> N;
		if(N > R){
			R = N;
		}
	}while(N != 0);
	cout << R << endl;
	return 0;
}