#include <bits/stdc++.h>
#define MAXN 100010

using namespace std;

struct jogo
{
	int x, y;

	bool operator < (const jogo &b)const
	{
		return (b.x - b.y) < (x - y);
	}
};

jogo jogos[MAXN];

int main(int argc, char** argv)
{
	int N, G;

	while(cin >> N >> G)
	{
		for(int i = 0; i < N; i++)
			cin >> jogos[i].x >> jogos[i].y;

		sort(jogos, jogos + N);

		int i = 0, r = 0;

		while(i < N && jogos[i].x > jogos[i].y)
			r += 3, i++;
		while(i < N && G > 0 && jogos[i].x == jogos[i].y)
			r += 3, i++, G--;
		while(i < N && G >= ((jogos[i].y - jogos[i].x) + 1))
			r += 3, G -= (jogos[i].y - jogos[i].x) + 1, i++;
		while(i < N && G >= ((jogos[i].y - jogos[i].x)))
			r += 1, G -= jogos[i].y - jogos[i].x, i++;

		cout << r << endl;
	}

	return 0;
}
