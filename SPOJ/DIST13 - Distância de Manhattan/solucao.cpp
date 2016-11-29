#include <iostream>
using namespace std;


int main(){
	int Xm, Ym,Xr,Yr;
	cin >> Xm >> Ym >> Xr >> Yr;
	
	int c1,c2;
	if(Xr-Xm > 0){
		c1 = Xr-Xm;
	}else{
		c1 = Xm - Xr;
	}
	
	if(Yr-Ym > 0){
		c2 = Yr -Ym;
	}else{
		c2 = Ym - Yr;
	}
	cout << (c1+c2) << endl;
	return 0;
}
