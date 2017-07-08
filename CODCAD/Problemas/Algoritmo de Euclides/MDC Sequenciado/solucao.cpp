#include <iostream>

using namespace std;

int mdc(int a, int b){
	if(b == 0)
		return a;
	return mdc(b, a%b);
}

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	int r, a;
	for (int i = 0; i < N; ++i)
	{
		cin >> a;
		if(i == 0)
			r = a;
		else
			r = mdc(a, r);
	}

	cout << r << endl;
	return 0;
}