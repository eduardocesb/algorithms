#include <bits/stdc++.h>
#define optimize std::ios::sync_with_stdio(0); cin.tie(0)
#define MAXN 1010

using namespace std;

class BIT_2D{
private:
	int N;
	int arvore[MAXN][MAXN];
public:
	BIT_2D(int N){
		this->N = N;
		memset(arvore, 0, sizeof(arvore));
	}

	void add(int a, int b, int valor){
		for (int i = a; i <= MAXN; i += (i & -i))
			for (int j = b; j <= MAXN; j += (j & -j))
				arvore[i][j] = max(arvore[i][j], valor);
	}

	int get(int a, int b){
		int r = 0;
		for (int i = a; i > 0; i -= (i & -i))
			for (int j = b; j > 0; j -= (j & -j))
				r = max(r, arvore[i][j]);

		return r;
	}
};

int main(int argc, char const *argv[])
{
	optimize;

	int T, N, a, b;

	cin >> T;

	while(T--){

		cin >> N;

		BIT_2D bit(N);

		int r = 0;

		for (int i = 0; i < N; ++i){
			cin >> a >> b;

			int m = bit.get(a, b) + 1;

			r = max(r, m);

			bit.add(a, b, m);
		}

		cout << r << endl;
	}

	return 0;
}