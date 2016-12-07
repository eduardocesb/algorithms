#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	if(x1 >= x3 && x2 >= x3 && (y1 + y2 >= y3)){
		cout << "S" << endl;
	}else if(y1 >= y3 && y2 >= y3 && (x1 + x2 >= x3)){
		cout << "S" << endl;
	}else if(y1 >= y3 && x2 >= y3 && (x1 + y2 >= x3)){
		cout << "S" << endl;
	}else if(x1 >= y3 && y2 >= y3 && (y1 + x2 >= x3)){
		cout << "S" << endl;
	}else if(x1 >= y3 && x2 >= y3 && (y1 + y2 >= x3)){
		cout << "S" << endl;
	}else if(y1 >= x3 && y2 >= x3 && (x1 + x2 >= y3)){
		cout << "S" << endl;
	}else if(y1 >= x3 && x2 >= x3 && (x1 + y2 >= y3)){
		cout << "S" << endl;
	}else if(x1 >= x3 && y2 >= x3 && (y1 + x2 >= y3)){
		cout << "S" << endl;
	}else if((y2 >= y3 && x2 >= x3) || (y2 >= x3 && x2 >= y3)){
		cout << "S" << endl;
	}else if((y1 >= y3 && x1 >= x3) || (y1 >= x3 && x1 >= y3)){
		cout << "S" << endl;
	}else{
		cout << "N" << endl;
	}
	return 0;
}