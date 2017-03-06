#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int n, m, r = 0, x;
	cin >> n >> m;
	int nums[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
	}

	for (int i = 0; i < n-1; ++i)
	{
		x = m - nums[i]; 
		if(x < 0){
			x *= -1;
		}
		r += x;
		nums[i+1] += m - nums[i];
	}

	x = m - nums[n-1]; 
	if(x < 0){
		x *= -1;
	}
	r += x;

	cout << r << endl;
	return 0;
}