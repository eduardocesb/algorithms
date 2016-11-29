#include <iostream>
using namespace std;

int main(){
	int r=0;
	int i=0;
	cin >> i;
	while(i!=0){
		if(i>r){
			r = i;
		}
		cin >> i;
	}
	cout << r << endl;
	return 0;
}
