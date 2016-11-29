#include <iostream>

using namespace std;

int main(){
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	while(!((A == 0) && (B == 0) && (C == 0) && (D == 0))){
		int r = ((C-A)*60) + (D-B);
		if(r < 0){
			r += 1440;
		}
		if(r == 0){
			r = 1440;
		}
		cout << r << endl;
		cin >> A >> B >> C >> D;
	}

	return 0;
}
