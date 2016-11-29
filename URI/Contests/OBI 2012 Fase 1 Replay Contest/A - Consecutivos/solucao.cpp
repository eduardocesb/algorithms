#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	int  max_total = 0;
	int max_atual = 0;
	int da_vez = -1;
	for (int i = 0; i < N; ++i)
	{
		int x;
		cin >> x;
		if(x == da_vez){
			max_atual++;
		}
		if(max_total < max_atual){
			max_total = max_atual;
		}
		if(x != da_vez){
			da_vez = x;
			max_atual = 0;
		}
	}

	cout << (max_total+1) << endl;
	return 0;
}