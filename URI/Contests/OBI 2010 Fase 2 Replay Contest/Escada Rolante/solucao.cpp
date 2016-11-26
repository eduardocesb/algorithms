#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	int r = 0;
	int tempo = 0;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		if(tempo == 0){
			r+=10;
			tempo = x + 10;
		}else if(x >= tempo){
			r += 10;
			tempo = x + 10;
		}else{
			int t = 10 - (tempo - x);
			r += t;
			tempo += t;
		}
	}
	cout << r << endl;
	return 0;
}