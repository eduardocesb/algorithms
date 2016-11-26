#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int p1, p2;
	cin >> p1 >> p2;
	if(p1 == 1 && p2 == 1){
		cout << "A" << endl;
	}else if(p1 == 1 && p2 == 0){
		cout << "B" << endl;
	}else if(p1 == 0){
		cout << "C" << endl;
	}
	return 0;
}