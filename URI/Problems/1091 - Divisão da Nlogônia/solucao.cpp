#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	while(N != 0){
		int I, J;
		cin >> I >> J;
		for (int x = 0; x < N; ++x)
		{
			int i, j;
			cin >> i >> j;
			if(i == I || j == J){
				cout << "divisa" << endl;
			}else if(i < I && j < J){
				cout << "SO" << endl;
			}else if(i < I && j > J){
				cout << "NO" << endl;
			}else if(i > I && j > J){
				cout << "NE" << endl;
			}else if(i > I && j < J){
				cout << "SE" << endl;
			}
		}
		cin >> N;
	}
	return 0;
}