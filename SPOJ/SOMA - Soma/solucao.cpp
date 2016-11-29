#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int r = 0;
	for(int i=0;i<n;i++){
		int e;
		cin >> e;
		r += e;
	}
	cout << r;
	return 0;
}
