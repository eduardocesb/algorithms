//https://codeforces.com/contest/1271/problem/C

#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pii pair<int, int>
#define ll long long
#define INF 2000000000
#define MAXN 200020

using namespace std;

vector<pii> pontos;

int nums[4];

int query(int x_min, int y_min, int x_max, int y_max)
{
	int r = 0;
	for(auto p : pontos)
		r += (x_min <= p.first && p.first <= x_max && y_min <= p.second && p.second <= y_max);

	return r;
}

int main(int argc, char const *argv[])
{
	optimize;

	int N, X, Y, x, y;


	cin >> N >> X >> Y;

	for(int i = 0; i < N; i++)
	{
		cin >> x >> y;

		pontos.push_back(pii(X - x, Y - y));
	}

	nums[0] = query(1, -INF, INF, INF); //DIREITA
	nums[1] = query(-INF, 1, INF, INF); //CIMA
	nums[2] = query(-INF, -INF, -1, INF); //ESQUERDA
	nums[3] = query(-INF, -INF, INF, -1); //BAIXO

	if(nums[0] >= nums[1] && nums[0] >= nums[2] && nums[0] >= nums[3])
		cout << nums[0] << endl << X - 1 << " " << Y << endl;
	else if(nums[1] >= nums[0] && nums[1] >= nums[2] && nums[1] >= nums[3])
		cout << nums[1] << endl << X << " " << Y - 1 << endl;
	else if(nums[2] >= nums[1] && nums[2] >= nums[0] && nums[2] >= nums[3])
		cout << nums[2] << endl << X + 1 << " " << Y << endl;
	else
		cout << nums[3] << endl << X << " " << Y + 1 << endl;
	return 0;
}