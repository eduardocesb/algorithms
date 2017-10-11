#include <bits/stdc++.h>

using namespace std;

class Bloco
{
private:
	deque<int> nums;
	long long soma;

public:
	Bloco()
	{
		soma = 0;
	}

	void add(int id, int valor)
	{
		soma += valor;
		nums.insert(nums.begin() + id, valor);
	}

	long long sum_(int id)
	{
		long long r = 0;
		for(int i = 0; i < id; i++)
			r += nums[i];

		return r;
	}

	long long sum()
	{
		return soma;
	}

	int size()
	{
		return nums.size();
	}

	pair<Bloco, Bloco> split()
	{
		Bloco a, b;
		int tam = size();
		for(int i = 0, pos = 0; i < tam; i++)
			if(i * 2 < tam)
				a.add(i, nums[i]);
			else
				b.add(pos++, nums[i]);

		return make_pair(a, b);
	}
};

class Blocos
{
private:
	deque<Bloco> blocos;
	int tam_bloco;

public:
	Blocos(int n)
	{
		tam_bloco = n;
		Bloco a;
		blocos.push_back(a);
	}

	void add(int id, int valor)
	{
		int i = 0;
		while(id > blocos[i].size())
			id -= blocos[i++].size();

		blocos[i].add(id, valor);

		if(blocos[i].size() == 2 * tam_bloco)
		{
			pair<Bloco, Bloco> b = blocos[i].split();
			blocos.erase(blocos.begin() + i);

			blocos.insert(blocos.begin() + i, b.second);
			blocos.insert(blocos.begin() + i, b.first);
		}
	}

	long long query(int a, int b)
	{
		int i = 0, j = 0;

		while(a >= blocos[i].size() && blocos.size() > i)
			a -= blocos[i++].size();

		while(b >= blocos[j].size() && blocos.size() > j)
			b -= blocos[j++].size();

		if(i == j)
			return blocos[i].sum_(b + 1) - blocos[i].sum_(a); 
		
		long long r = blocos[i].sum() - blocos[i].sum_(a) + blocos[j].sum_(b + 1);

		for(i++; i < j; i++)
			r += blocos[i].sum();

		return r;
	}
};

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false); cin.tie(0);
	int N, Q, x, y;
	char op;

	cin >> N;

	Blocos nums(sqrt(N));
	for(int i = 0; i < N; nums.add(i++, x))
		cin >> x;

	cin >> Q;

	for(int i = 0; i < Q;i++){
		cin >> op >> x >> y;
		if(op == 'I')
			nums.add(x, y);
		else
			cout << nums.query(x - 1, y - 1) << endl;
	}
	return 0;
}