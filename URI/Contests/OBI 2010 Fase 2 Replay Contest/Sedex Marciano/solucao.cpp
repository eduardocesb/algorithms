#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int l, a, p, r;
	cin >> l >> a >> p >> r;
	bool cabe = (l*l) + (a*a) + (p*p) <= 4*(r*r);
	if(cabe){
		cout << 'S' << endl;
	}else{
		cout << 'N' << endl;
	}
	return 0;
}