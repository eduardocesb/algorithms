#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int anterior;
	bool c = true, d = true;
	for (int i = 0; i < 5; ++i)
	{
		int x;
		cin >> x;
		if(i != 0 && x > anterior){
			d = false;
		}else if(i != 0 && x < anterior){
			c = false;
		}

		anterior = x;
	}

	if(c){
		cout << "C" << endl;
	}else if(d){
		cout << "D" << endl;
	}else{
		cout << "N" << endl;
	}
	return 0;
}