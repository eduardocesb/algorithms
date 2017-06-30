#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int H, P , F, D;
	cin >> H >> P >> F >> D;
	H *= D;
	P *= D;
	F *= D;

	if((F < P && (H > F && H < P)) || (F > P && (F < H || P > H))){
		cout << "S" << endl;
	}else{
		cout << "N" << endl;
	}
	return 0;
}