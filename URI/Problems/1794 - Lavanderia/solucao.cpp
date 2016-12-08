#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, LA, LB, SA, SB;
	cin >> N >> LA >> LB >> SA >> SB;
	if(N >= LA && N <= LB && N >= SA && N <= SB){
		cout << "possivel" << endl;
	}else{
		cout << "impossivel" << endl;
	}
	return 0;
}