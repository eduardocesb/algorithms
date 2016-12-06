#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int X1, Y1, X2, Y2;
	cin >> X1 >> Y1 >> X2 >> Y2;
	while(X1 != 0 || Y1 != 0 || X2 != 0 || Y2 != 0){
		if(X1 == X2 && Y1 == Y2){
			cout << "0" << endl;
		}else if(X1 == X2 || Y1 == Y2){
			cout << "1" << endl;
		}else if((X1 + Y1 == X2 + Y2) || (X1 - Y1 == X2 - Y2)){
			cout << "1" << endl;
		}else{
			cout << "2" << endl;
		}
		cin >> X1 >> Y1 >> X2 >> Y2;
	}
	return 0;
}