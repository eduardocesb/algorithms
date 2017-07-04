#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int comida;
	cin >> comida;
	int nums[3];
	for (int i = 0; i < 3; ++i)
	{
		cin >> nums[i];
	}

	sort(nums, nums + 3);
	int r = 0;
	for (int i = 0; i < 3; ++i)
	{
		if(nums[i] <= comida){
			comida -= nums[i];
			r++;
		}
	}

	cout << r << endl;
	return 0;
}