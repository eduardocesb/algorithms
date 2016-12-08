#include <iostream>

using namespace std;


int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int x, y;
		cin >> x >> y;
		int r = 0;
		
		if(x%2 == 0){
			x++;
		}

		int qtd = 0;
		while(qtd < y){
			r+=x;
			x+=2;
			qtd++;
		}
		
		cout << r << endl;
	}
	return 0;
}