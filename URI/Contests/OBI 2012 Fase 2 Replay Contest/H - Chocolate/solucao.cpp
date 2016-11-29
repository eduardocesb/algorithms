#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int L;
	cin >> L;
	int s = 2;
	int r = 1;
	while(s <= L){
		s *= 2;
		r *= 4;
	}
	cout << r << endl;
	return 0;
}