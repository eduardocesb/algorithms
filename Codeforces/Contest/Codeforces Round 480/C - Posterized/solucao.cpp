#include <bits/stdc++.h>
#define MAXN 100010
#define optimize ios::sync_with_stdio(0); cin.tie(0)

using namespace std;

int N, K;
int nums[MAXN];
int grupo[300];

int main(int argc, char** argv)
{
	memset(grupo, -1, sizeof grupo);
	optimize;

	cin >> N >> K;

	for(int i = 1; i <= N; i++)
		cin >> nums[i];

	for(int i = 1; i <= N; i++)
	{
		if(grupo[nums[i]] != -1) continue;

		int ultimogrupo = -1;

		//Pego o ultimo cara sem grupo maior que nums[i] - K...
		for(int j = nums[i]; j > max(0, nums[i] - K); j--)
			if(grupo[j - 1] != -1)
			{
				ultimogrupo = j;
				break;
			}
			
		if(ultimogrupo == -1)
			ultimogrupo = max(0, nums[i] - K + 1);

		//Se eu conseguir colocar o nums[i] no mesmo grupo do grupo anterior a ele eu coloco...
		if(grupo[ultimogrupo - 1] != -1 && nums[i] - grupo[ultimogrupo - 1] < K)
			ultimogrupo = grupo[ultimogrupo - 1];

		for(int j = ultimogrupo; j <= nums[i]; j++)
			grupo[j] = ultimogrupo;
	}

	for(int i = 1; i <= N; i++)
		cout << grupo[nums[i]] << " ";

	cout << endl;

	return 0;
}
