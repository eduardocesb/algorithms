#include <iostream>

using namespace std;

int r(double x){

	int r=0;
	while(x > 1){
		r++;
		x = x/2;
	}

	return r;
}

int main(){



	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		double x;
		cin >> x;
		cout << r(x) << " dias" << endl;
	}
	return 0;
}
