#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int H1, M1, H2, M2;
	cin >> H1 >> M1 >> H2 >> M2;
	while(H1 != 0 || M1 != 0 || H2 != 0 || M2 != 0){
		int r = 0;
		if(H2 < H1){
			r = 24 + H2 - H1;
			r *= 60;
		}else if(H1 == H2 && M2 < M1){
			r = 24 * 60;
		}else{
			r = H2 - H1;
			r *= 60;
		}

		if(M2 < M1){
			r -= M1 - M2;
		}else{
			r += M2 - M1;
		}
		cout << r << endl;
		cin >> H1 >> M1 >> H2 >> M2;
	}
	return 0;
}