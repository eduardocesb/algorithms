#include <bits/stdc++.h>
#define optimize std::ios::sync_with_stdio(0); cin.tie(0);
#define MAXN 100100

using namespace std;

int prefixo[MAXN], sufixo[MAXN], nums[MAXN];

int main(int argc, char const *argv[])
{
	//optimize;
	int N, r = 0;
	cin >> N;

	for (int i = 1; i <= N; prefixo[i] = max(prefixo[i - 1], nums[i]), i++)
		cin >> nums[i];

	for (int i = N; i; --i)
		sufixo[i] = max(sufixo[i + 1], nums[i]);

	for (int i = 1; i <= N; ++i)
		if(nums[i] < min(prefixo[i - 1], sufixo[i + 1]))
			r++;

	cout << r << endl;
	return 0;
}