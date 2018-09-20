#include <bits/stdc++.h>

using namespace std;

int calc(int a, int b, string op)
{
	if(op == "+") return a + b;
	if(op == "-") return a - b;
	return a * b;
}

int main(int argc, char** argv)
{
	int N, a, b, r, v, d;

	string op, x;

	scanf("%d", &N);

	while(N--)
	{
		cin >> a >> op >> b >> x >> r;

		cout << "E";

		v = calc(a, b, op);

		d = abs(v - r);

		for(int i = 0; i < d; i++)
			cout << "r";
		cout << "ou!\n";
	}

	return 0;
}
