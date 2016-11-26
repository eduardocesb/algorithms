#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int tam, N;
	cin >> tam >> N;
	int ultimo = 1;
	int l1 = 0;
	int r = 0;
	int x;
	for (int i = 0; i < N; ++i)
	{
		cin >> x;
		if(i == 0){
			l1 = x-1;
			ultimo = x;
		}else{
			if(r < (x - ultimo)){
				r = (x - ultimo)-1;
			}
			ultimo = x;
		}
	}
	cout << max(((r+1)/2), max(l1, tam-x )) << endl;
	return 0;
}