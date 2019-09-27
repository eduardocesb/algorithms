#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define pii pair<int, int>
#define INF 1000000000
#define MAXN 100100

using namespace std;

int main(int argc, char const *argv[])
{
	// optimize;

	int N;

	int freq[] = {0, 0, 0, 0};

	char c;

	cin >> N >> c;

	char palpite[4][110], s[110];

	while(N--)
	{
		scanf(" %[^\n]s", s);

		for(int i = 0; i < 4; i++)
			scanf(" %[^\n]s", palpite[i]);

		scanf(" %[^\n]s", s);

		for(int i = 0; i < 4; i++)
		{
			scanf(" %[^\n]s", s);

			freq[i] += !strcmp(palpite[i], s);
		}
	}


	int menor;

	for(int i = 0; i < 4; i++)
		if(!i || menor > freq[i])
			menor = freq[i];

	vector<int> resp;

	for(int i = 0; i < 4; i++)
		if(freq[i] == menor) resp.push_back(i + 1);

	for(int i = 0; i < (int)resp.size(); i++)
		cout << resp[i] << " \n"[i == ((int)resp.size()) - 1];

	return 0;
}