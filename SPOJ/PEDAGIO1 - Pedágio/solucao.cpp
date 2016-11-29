#include <iostream>
using namespace std;

int main(){
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	int r = 0;
	r += (a/b)*d;
	r += a*c;
	cout << r << endl;
	return 0;
}
