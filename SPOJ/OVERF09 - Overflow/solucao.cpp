#include <iostream>

using namespace std;

int main(){
	
	int max;
	cin >> max;
	int n1, n2;
	char op;
	cin >> n1 >> op >> n2;
	if(op == '+'){
		if(n1 + n2 <= max){
			cout << "OK"<< endl;
		}else{
			cout << "OVERFLOW" << endl;
		}
	}else if(op == '*'){
		if(n1 * n2 <= max){
			cout << "OK"<< endl;
		}else{
			cout << "OVERFLOW" << endl;
		}
	}
	return 0;
}
