#include <iostream>
using namespace std;

int main(){
	int a,b,c,d,e;
	cin >> a >> b >> c >> d >> e;
	if(a > b && b > c && c > d && d > e){
		cout << 'D' << endl;
	}else if(a < b && b < c && c < d && d < e){
		cout << 'C' << endl;
	}else{
		cout << 'N' << endl;
	}
	
	return 0;
}
