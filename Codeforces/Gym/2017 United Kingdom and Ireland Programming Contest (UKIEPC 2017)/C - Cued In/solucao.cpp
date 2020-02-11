#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 2000000000
#define pii pair<int, int>
#define ll long long
#define MAXN 100100
#define MAXL 23

using namespace std;

int score(string S)
{
	if(S == "red") return 1;
	if(S == "yellow") return 2;
	if(S == "green") return 3;
	if(S == "brown") return 4;
	if(S == "blue") return 5;
	if(S == "pink") return 6;
	return 7;
}

int main(int argc, char const *argv[])
{
	optimize;

	int N, R = 0, sum = 0, maior = 0;

	cin >> N;

	string S;

	for(int i = 0; i < N; i++)
	{
		cin >> S;

		if(S == "red") R++;
		
		sum += score(S);

		maior = max(maior, score(S));
	}
	
	int ans = (maior * R) + sum;

	cout << (R == N ? 1 : ans) << endl;

	return 0;
}