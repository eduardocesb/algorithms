#include <iostream>
#include <cmath>

using namespace std;

int main(){

	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		long long int r = (pow(2, x))/12000;
		cout << r << " kg" << endl;
	}

	return 0;
}
