#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, Q;
	cin >> N >> Q;
	double r;
	switch(N){
		case 1:
			r = 4;
			break;
		case 2:
			r = 4.5;
			break;
		case 3:
			r = 5;
			break;
		case 4:
			r = 2;
			break;
		case 5:
			r = 1.5;
			break;
	}

	r *= Q;
	printf("Total: R$ %.2f\n", r);
	return 0;
}