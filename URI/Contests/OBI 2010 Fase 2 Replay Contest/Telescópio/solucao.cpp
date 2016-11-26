#include <iostream>
#define OLHO 40000000


using namespace std;

int main(int argc, char const *argv[])
{
	int telescopio;
	cin >> telescopio;
	int N;
	cin >> N;
	int r = 0;
	for (int i = 0; i < N; ++i)
	{
		int x;
		cin >> x;
		if((x*telescopio) >= OLHO){
			r++;
		}
	}
	cout << r << endl;
	return 0;
}