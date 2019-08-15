#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)

using namespace std;


int main(int argc, char** argv)
{
	optimize;
	
	int N;

	cin >> N;
	
	vector<int> nums(N);
	
	for(int i = 0; i < N; i++)
		cin >> nums[i];
	
	sort(nums.begin(), nums.end());
	
	int j = 0, best = 0;
	
	for(int i = 0; i < N; i++)
	{
		while(nums[i] - 5 > nums[j]) j++;
		best = max(best, (i - j) + 1);
	}
	
	cout << best << endl;
	
	return 0;
}
