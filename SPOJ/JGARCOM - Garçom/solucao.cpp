#include <iostream>

using namespace std;

int main(){

	int n,r=0;
	cin >> n;
	for(int i=0;i<n;i++){
		int a,b;
		cin >> a >> b;
		if(a>b){
			r+= b;
		}
	}
	cout << r << endl;
	return 0;
}
