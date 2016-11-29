#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int qtd = 0;
	int nums[n];
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		nums[i] = x;
		qtd += x;
	}
	int r = qtd/2;
	//cout << "R " << r << endl;
	qtd = 0;
	for (int i = 0; i < n; ++i)
	{
		qtd += nums[i];
		if(qtd == r){
			cout << (i+1) << endl;
			break;
		}
	}
	return 0;
}