#include <bits/stdc++.h>
#define ll long long
#define MAXN 200200

using namespace std;

int nums[MAXN];
ll S = 0LL;

unordered_map<ll, int> frequencia;
vector<int> resp;

int main(int argc, char** argv)
{
	int N;

	cin >> N;

	for(int i = 0; i < N; i++)
	{
		cin >> nums[i];
		S += nums[i];
		frequencia[nums[i]]++;
	}

	for(int i = 0; i < N; i++)
	{
		ll ss = S - nums[i];
		if(ss % 2) continue;

		ll meio = ss / 2LL;

		if(frequencia.find(meio) != frequencia.end() && ((meio != nums[i]) || (meio == nums[i] && frequencia[meio] > 1)))
			resp.push_back(i + 1);
	}

	cout << (int)resp.size() << endl;
for(auto x : resp)
		cout << x << " ";
	cout << endl;

	return 0;
}
