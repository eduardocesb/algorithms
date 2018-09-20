#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(0); cin.tie(0)

using namespace std;

int main(int argc, char** argv)
{
	optimize;
	string x, y;

	vector<string> nums;

	while(cin >> x && !cin.eof())
	{
		if(x == "1")
			nums.clear();
		else if(x == "0")
		{
			sort(nums.begin(), nums.end());
for(auto p : nums)
				cout << "Package " << p << endl;
			cout << endl;
		}
		else
		{
			cin >> y;
			nums.push_back(y);
		}
	}

	return 0;
}
