#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, r = 0;
	cin >> N;
	string a, b;
	cin >> a >> b;
	for (int i = 0; i < N; ++i)
	{
		if(a[i] == b[i]){
			r++;
		}
	}
	cout << r << endl;
	return 0;
}