#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, M;
	cin >> N >> M;
	int r = 0, incremento = 0;
	for (int i = 0; i < N; ++i)
	{
		int x;
		cin >> x;
		x += incremento;
		incremento = M - x;
		if(incremento < 0){
			r += incremento*-1;
		}else{
			r += incremento;
		}
	}

	cout << r << endl;
	return 0;
}