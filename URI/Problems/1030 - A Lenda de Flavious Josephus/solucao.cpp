#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	int NC;
	cin >> NC;
	int teste = 1;
	for (int i = 1; i <= NC; ++i)
	{
		int n, k;
		cin >> n >> k;
		int posicao = 0;
		vector<int> nums;
		for (int j = 1; j <= n; j++)
			nums.push_back(j);
		while(nums.size() > 1){
			posicao += k-1;
			posicao = posicao % nums.size();
			nums.erase(nums.begin()+posicao);
		}
		cout << "Case " << teste << ": " << nums[0] << endl;
		teste++;
	}
	return 0;
}