#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int n, k, min = 0;
	cin >> n;
	int nums[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
	}

	cin >> k;
	n--;
	while(true){
		if(nums[min] + nums[n] == k){
			cout << nums[min] << " " << nums[n];
			break;
		}else if(nums[min] + nums[n] > k){
			n--;
		}else{
			min++;
		}
	}
	return 0;
}