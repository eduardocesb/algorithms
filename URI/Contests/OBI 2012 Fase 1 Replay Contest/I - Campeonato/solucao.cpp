#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int a,b,golsC,d,e,golsF;
	cin >> a >> b >> golsC >> d >> e >> golsF;
	int pontosC =  (a*3)+b;
	int pontosF =  (d*3)+e;
	if(pontosF > pontosC){
		cout << "F" << endl;
	}else if(pontosC > pontosF){
		cout << "C" << endl;
	}else if(golsC > golsF){
		cout << "C" << endl;
	}else if(golsF > golsC){
		cout << "F" << endl;
	}else{
		cout << "=" << endl;
	}
	return 0;
}