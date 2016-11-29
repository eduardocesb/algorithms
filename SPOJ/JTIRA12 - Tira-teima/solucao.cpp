#include <iostream>

using namespace std;

int main(){
	int a,b;
	cin >> a >> b;
	if(a >=0 && a <= 432 && b >= 0 && b <= 468){
		cout << "dentro" << endl;
	}else{
		cout << "fora" << endl;
	}

	return 0;
}
