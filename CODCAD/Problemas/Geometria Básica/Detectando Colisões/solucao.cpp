#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int X0, X1, X2, X3, Y0, Y1, Y2, Y3;
	cin >> X0 >> Y0 >> X1 >> Y1 >> X2 >> Y2 >> X3 >> Y3;
	if(X2 <= X1 && X2 >= X0 && Y3 >= Y0 && Y2 <= Y1)
		cout << 1 << endl;
	else if(X3 <= X1 && X3 >= X0 && Y2 <= Y1 && Y3 >= Y0)
		cout << 1 << endl;
	else if(X2 <= X1 && X3 >= X0 && Y2 <= Y1 && Y2 >= Y0)
		cout << 1 << endl;
	else if(X2 <= X1 && X3 >= X0 && Y3 <= Y1 && Y3 >= Y0)
		cout << 1 << endl;
	else
		cout << 0 << endl;
	return 0;
}