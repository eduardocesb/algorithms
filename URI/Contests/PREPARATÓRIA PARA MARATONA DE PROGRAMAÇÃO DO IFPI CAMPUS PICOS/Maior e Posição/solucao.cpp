#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int x, pos, maior;
	for (int i = 1; i <= 100; ++i)
	{
		cin >> x;
		if(i == 1 || x > maior){
			maior = x;
			pos = i;
		}
	}

	cout << maior << endl;
	cout <<  pos << endl;
	return 0;
}