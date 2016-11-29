#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int x,y,a,b,c,d;
	cin >> x >> y >> a >> b >> c >> d;
	if((a <= x) && (c <= x) && ((b+d) <= y)){
		cout << "S" << endl;
	}else if((a <= x) && (d <= x) && ((b+c) <= y)){
		cout << "S" << endl;
	}else if((b <= x) && (c <= x) && ((a+d) <= y)){
		cout << "S" << endl;
	}else if((b <= x) && (d <= x) && ((a+c) <= y)){
		cout << "S" << endl;
	}else if((b <= y) && (d <= y) && ((a+c) <= x)){
		cout << "S" << endl;
	}else if((b <= y) && (c <= y) && ((a+d) <= x)){
		cout << "S" << endl;
	}else if((a <= y) && (d <= y) && ((b+c) <= x)){
		cout << "S" << endl;
	}else if((a <= y) && (c <= y) && ((b+d) <= x)){
		cout << "S" << endl;
	}else{
		cout << "N" << endl;
	}
	return 0;
}