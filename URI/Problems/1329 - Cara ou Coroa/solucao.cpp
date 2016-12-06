#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	while(N != 0){
		int j = 0, m = 0;
		for (int i = 0; i < N; ++i)
		{
			int x;
			cin >> x;
			if (x == 0)
			{
				m++;
			}else{
				j++;
			}
		}
		cout << "Mary won " << m << " times and John won " << j << " times" << endl;
		cin >> N;
	}
	return 0;
}