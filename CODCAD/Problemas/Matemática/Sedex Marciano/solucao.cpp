#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
	unsigned long long L, A, P, R;
	cin >> L >> A >> P >> R;
	//L² + A² + P² <= 4.R²
	R = pow(R, 2);
	R *= 4;
	L = pow(L, 2);
	A = pow(A, 2);
	P = pow(P, 2);
	if(L + A + P <= R){
		cout << 'S' << endl;
	}else{
		cout << 'N' << endl;
	}
	return 0;
}