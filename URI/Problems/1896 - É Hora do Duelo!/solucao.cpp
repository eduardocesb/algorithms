//https://www.urionlinejudge.com.br/judge/pt/problems/view/1896
// Solution O(2^N)

#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pii pair<int, int>
#define ll long long
#define INF 2000000000 
#define MAXN 22

using namespace std;

int nums[MAXN][3], N;

bool solve(int i, int A, int B, int C)
{
	if(A == 0 && B == 0 && C == 0) return true;
	if(A < 0 || B < 0 || C < 0 || i == N) return false;

	return max(solve(i + 1, A, B, C), solve(i + 1, A - nums[i][0], B - nums[i][1], C - nums[i][2]));
}

int main(int argc, char const *argv[])
{
	optimize;

	int A, B, C;

	cin >> N >> A >> B >> C;

	for(int i = 0; i < N; i++)
	{
		cin >> nums[i][0] >> nums[i][1] >> nums[i][2];
		if(nums[i][0] == A && nums[i][1] == B && nums[i][2] == C) nums[i][0] = nums[i][1] = nums[i][2] = 0;
	}


	cout << (solve(0, A, B, C) ? 'Y' : 'N') << endl;

	return 0;
}